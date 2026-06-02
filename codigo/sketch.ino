#include <WiFi.h>
#include <PubSubClient.h>

#define SENSOR_PIN 34
#define RELE_PIN 25

// =====================
// CONFIGURAÇÃO WIFI
// =====================
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// =====================
// CONFIGURAÇÃO MQTT
// =====================
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

int valorUmidade = 0;

// =====================
// CONEXÃO WIFI
// =====================
void setupWifi() {

  Serial.println("Conectando ao WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("================================");
  Serial.println("WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("================================");
}

// =====================
// CONEXÃO MQTT
// =====================
void reconnectMQTT() {

  while (!client.connected()) {

    Serial.println("Conectando ao Broker MQTT...");

    String clientId = "ESP32-Irrigacao-";
    clientId += String(random(1000));

    if (client.connect(clientId.c_str())) {

      Serial.println("MQTT conectado com sucesso!");
      Serial.println("================================");

    } else {

      Serial.print("Falha MQTT. Codigo: ");
      Serial.println(client.state());

      Serial.println("Tentando novamente em 2 segundos...");
      delay(2000);
    }
  }
}

// =====================
// SETUP
// =====================
void setup() {

  Serial.begin(115200);
  delay(2000);

  pinMode(RELE_PIN, OUTPUT);

  Serial.println("================================");
  Serial.println("Sistema de Irrigacao Inteligente");
  Serial.println("================================");

  setupWifi();

  client.setServer(mqtt_server, mqtt_port);
}

// =====================
// LOOP PRINCIPAL
// =====================
void loop() {

  if (!client.connected()) {
    reconnectMQTT();
  }

  client.loop();

  valorUmidade = analogRead(SENSOR_PIN);

  Serial.print("Umidade do solo: ");
  Serial.println(valorUmidade);

  // Publica valor do sensor
  String msgUmidade = String(valorUmidade);

  client.publish(
    "cidade/horta/umidade",
    msgUmidade.c_str()
  );

  Serial.println("MQTT -> Umidade enviada");

  // Lógica da irrigação
  if (valorUmidade < 2000) {

    digitalWrite(RELE_PIN, HIGH);

    Serial.println("Status: SOLO SECO -> Irrigando");

    client.publish(
      "cidade/horta/status",
      "SOLO SECO - Irrigando"
    );

  } else {

    digitalWrite(RELE_PIN, LOW);

    Serial.println("Status: SOLO UMIDO -> Irrigacao desligada");

    client.publish(
      "cidade/horta/status",
      "SOLO UMIDO - Irrigacao desligada"
    );
  }

  Serial.println("--------------------------------");

  delay(3000);
}
