// Incluir a biblioteca para fazer a comunicação com o Bluetooth
#include <SoftwareSerial.h>

// Pinos do Arduino:
// RX(10) conectado no TX do Bluetooth
// TX(11) conectado no RX do Bluetooth
SoftwareSerial BluetoothSerial(10, 11); // RX, TX
int valor = 0;

void setup() {
  // A taxa de transmissão da Serial e da SoftwareSerial devem ser iguais
  // Definir taxa de transmissão de dados da Serial
  Serial.begin(9600);
  // Definir taxa de transmissão de dados da SoftwareSerial
  BluetoothSerial.begin(9600);
  // Definir o pino 9 como saída
  pinMode(9, OUTPUT);
}

void loop() {
  // Verificar se há dados vindos do Bluetooth
  if (BluetoothSerial.available()) {
    // Ler dado do Bluetooth
    valor = BluetoothSerial.read();
  }
  // Se o valor for 20, no caso botão de acender, manda um sinal
  // para ligar o fio conectado no pino 9
  if (valor == 20)
    digitalWrite(9, HIGH);
  // Caso o valor seja 150, no caso o botão de apagar, manda sinal 
  // para desligar o fio conectado no pino 9
  else if (valor == 150)
    digitalWrite(9, LOW);
  
  // Aguarda 0,1s para repetir a leitura
  delay(100);
}
