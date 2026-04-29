#define SENSOR_PIN 34
#define RELE_PIN 26

int valorUmidade = 0;

void setup() {
  Serial.begin(115200);
  pinMode(RELE_PIN, OUTPUT);
}

void loop() {
  valorUmidade = analogRead(SENSOR_PIN);

  Serial.print("Umidade: ");
  Serial.println(valorUmidade);

  if (valorUmidade < 2000) {
    digitalWrite(RELE_PIN, HIGH);
    Serial.println("Solo seco - Irrigando");
  } else {
    digitalWrite(RELE_PIN, LOW);
    Serial.println("Solo úmido - Parando irrigação");
  }

  delay(2000);
}
