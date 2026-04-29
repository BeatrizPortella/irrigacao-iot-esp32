# Sistema de Irrigação Inteligente com ESP32 🌱

## 📌 Descrição
Este projeto apresenta um sistema de Internet das Coisas (IoT) voltado para agricultura urbana, com foco no monitoramento da umidade do solo e automação da irrigação.

A solução utiliza o microcontrolador ESP32, sensor de umidade do solo e comunicação via protocolo MQTT.

---

## 🎯 Objetivo
Automatizar o processo de irrigação em hortas urbanas, reduzindo o desperdício de água e contribuindo para cidades mais sustentáveis (ODS 11).

---

## ⚙️ Funcionamento

1. O sensor mede a umidade do solo
2. O ESP32 processa os dados
3. Se a umidade estiver baixa:
   - O relé é acionado
   - A bomba é ligada
4. Os dados são enviados via MQTT
5. O sistema pode ser monitorado remotamente

---

## 🔌 Hardware Utilizado

- ESP32 DevKit V1
- Sensor de Umidade do Solo
- Módulo Relé
- Bomba d’água
- Protoboard e jumpers

---

## 🌐 Comunicação MQTT

Broker utilizado: HiveMQ

Tópicos:

- `cidade/horta/umidade`
- `cidade/horta/comando`
- `cidade/horta/status`

---

## 💻 Tecnologias

- Arduino IDE
- C++
- MQTT
- Wokwi
- Wi-Fi

---

## ▶️ Como Executar

1. Clone o repositório:
