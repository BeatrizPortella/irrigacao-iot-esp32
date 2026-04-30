#define SENSOR_PIN 34
#define RELE_PIN 25

int valorUmidade = 0;

void setup() {
  Serial.begin(115200);
  delay(2000); // garante que o serial inicialize
  pinMode(RELE_PIN, OUTPUT);
  Serial.println("Sistema de Irrigacao Iniciado");
} 

void loop() {
  valorUmidade = analogRead(SENSOR_PIN);
  Serial.print("Umidade do solo: ");
  Serial.println(valorUmidade);

  // Ajuste de limite (pode mexer se quiser)
  if (valorUmidade < 2000) {
    digitalWrite(RELE_PIN, HIGH);
    Serial.println("Status: SOLO SECO -> Irrigando");
  } else {
    digitalWrite(RELE_PIN, LOW);
    Serial.println("Status: SOLO UMIDO -> Irrigacao desligada");
  } 

  Serial.println("-----------------------------");
  delay(2000);
} 
