// Incluir a biblioteca para fazer a comunicação com o Bluetooth
#include <SoftwareSerial.h>
// Incluir a biblioteca para movimentar o servo-motor
#include <Servo.h>

// Pinos do Arduino:
// RX(10) conectado no TX do Bluetooth
// TX(11) conectado no RX do Bluetooth
SoftwareSerial BluetoothSerial(10, 11); // RX, TX
// Criar variável de controle do servo-motor
Servo mServo;
int valor = 0;

void setup() {
  // A taxa de transmissão da Serial e da SoftwareSerial devem ser iguais
  // Definir taxa de transmissão de dados da Serial
  Serial.begin(9600);
  // Definir taxa de transmissão de dados da SoftwareSerial
  BluetoothSerial.begin(9600);
  // Definir o pino 9 do Arduino como o controle do servo-motor
  mServo.attach(9);
}

void loop() {
  // Verificar se há dados vindos do Bluetooth
  if (BluetoothSerial.available()) {
    // Ler ângulo vindo do Bluetooth
    valor = BluetoothSerial.read();
    // Rotacionar o servo-motor para o ângulo lido
    mServo.write(valor);
  }
  // Verificar se o valor do ângulo está entre 10 e 170
  // para notificar ao Android se o dado é inválido(I) ou válido(V)
  if (valor < 10 || valor > 170)
     BluetoothSerial.write("I");
  else 
     BluetoothSerial.write("V");

  // Aguarda 0,1s para repetir a leitura
  delay(100);
}
