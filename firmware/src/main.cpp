#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <math.h>

/*
 * Starter telemetry firmware.
 * Provide credentials via build environment or a local secrets header.
 * Never commit real credentials to version control.
 */
#ifndef WIFI_SSID
#define WIFI_SSID "CHANGE_ME"
#endif
#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD "CHANGE_ME"
#endif
#ifndef MQTT_HOST
#define MQTT_HOST "test.mosquitto.org"
#endif
#ifndef MQTT_PORT
#define MQTT_PORT 1883
#endif
#ifndef MQTT_TOPIC
#define MQTT_TOPIC "lab/esp32-sensor-01/telemetry"
#endif

static constexpr uint32_t PUBLISH_INTERVAL_MS = 5000;
static WiFiClient wifiClient;
static PubSubClient mqttClient(wifiClient);
static uint32_t lastPublishMs = 0;

static void connectWiFi()
{
    if (WiFi.status() == WL_CONNECTED) return;

    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    const uint32_t started = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - started < 15000) {
        delay(250);
    }
}

static bool connectMQTT()
{
    if (mqttClient.connected()) return true;
    String clientId = String("esp32-sensor-") + String((uint32_t)ESP.getEfuseMac(), HEX);
    return mqttClient.connect(clientId.c_str());
}

void setup()
{
    Serial.begin(115200);
    delay(200);
    Serial.println();
    Serial.println("ESP32 IoT sensor PCB - telemetry starter");

    mqttClient.setServer(MQTT_HOST, MQTT_PORT);
    connectWiFi();

    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("Wi-Fi connected, IP: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("Wi-Fi not connected; retrying in loop.");
    }
}

void loop()
{
    if (WiFi.status() != WL_CONNECTED) {
        connectWiFi();
        delay(100);
        return;
    }

    if (!mqttClient.connected() && !connectMQTT()) {
        Serial.println("MQTT connect failed; retrying.");
        delay(2000);
        return;
    }

    mqttClient.loop();

    const uint32_t now = millis();
    if (now - lastPublishMs >= PUBLISH_INTERVAL_MS) {
        lastPublishMs = now;

        // Placeholder values: replace with real sensor reads and validated conversions.
        const float temperatureC = NAN;
        const float humidityPct = NAN;

        char payload[192];
        snprintf(payload, sizeof(payload),
                 "{\"device_id\":\"esp32-sensor-01\",\"uptime_ms\":%lu,"
                 "\"temperature_c\":null,\"humidity_pct\":null,\"sensor_status\":\"not_configured\"}",
                 (unsigned long)now);

        (void)temperatureC;
        (void)humidityPct;

        const bool ok = mqttClient.publish(MQTT_TOPIC, payload);
        Serial.printf("MQTT publish %s: %s\n", ok ? "OK" : "FAILED", payload);
    }
}
