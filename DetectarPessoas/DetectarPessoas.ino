// Incluir a biblioteca para fazer a comunicação com o Bluetooth
#include <SoftwareSerial.h>
// Incluir a biblioteca para utilizar o sonar
#include <NewPing.h>

#define TRIGGER_PIN  9  // Pino do Arduino ligado no trigger do sonar
#define ECHO_PIN     8  // Pino do Arduino ligado no echo do sonar
#define MAX_DISTANCE 100 // Máxima distância para o sonar checar o obstáculo em cm(funciona até 400-500cm)

// Pinos do Arduino:
// RX(10) conectado no TX do Bluetooth
// TX(11) conectado no RX do Bluetooth
SoftwareSerial BluetoothSerial(10, 11); // RX, TX
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int valor = 0;

void setup() {
  // A taxa de transmissão da Serial e da SoftwareSerial devem ser iguais
  // Definir taxa de transmissão de dados da Serial
  Serial.begin(9600);
  // Definir taxa de transmissão de dados da SoftwareSerial
  BluetoothSerial.begin(9600);
  // Definir o pino A0 como entrada
  pinMode(0, INPUT);
}

void loop() {
  // Ler distância do sonar
  valor = Serial.print(sonar.ping_cm());
  // Enviar o dado ao Bluetooth
  BluetoothSerial.write(valor);

  // Aguarda 0,1s para repetir a leitura
  delay(100);
}
