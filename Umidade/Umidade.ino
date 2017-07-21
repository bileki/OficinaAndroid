// Incluir a biblioteca para fazer a comunicação com o Bluetooth
#include <SoftwareSerial.h>

// Pinos do Arduino:
// RX(10) conectado no TX do Bluetooth
// TX(11) conectado no RX do Bluetooth
SoftwareSerial mySerial(10, 11); // RX, TX
int valor = 0, resp = 0;

void setup() {
  // A taxa de transmissão da Serial e da SoftwareSerial devem ser iguais
  // Definir taxa de transmissão de dados da Serial
  Serial.begin(9600);
  // Definir taxa de transmissão de dados da SoftwareSerial
  BluetoothSerial.begin(9600);
  // Definir pino A0 do Arduino como entrada
  pinMode(0, INPUT);
}

void loop() {
  // Ler o valor analógico do pino ligado ao sensor de umidade
  valor = analogRead(0);

  // Se o valor lido for menor que 900, há chuva,
  // então envia ao bluetooth se está chovendo(S) ou não(N)
  if (valor < 900)
    mySerial.write("S");
  else 
    mySerial.write("N");

/* Se quiser executar alguma tarefa dependendo da chuva,
 *  pode-se criar funções automáticas ou receber ações pré-definidas
 *  por exemplo:
  // Verificar se há dados vindos do Bluetooth
  if (mySerial.available()) {
    // Ler resposta vinda do Bluetooth
    resp = mySerial.read();   
  }

  if (valor < 900)
    fecharJanela();
  
  // Se receber o comando fechar janela:
  if (resp == 0)
  	fecharJanela();
  // Se receber o comando desligar sprinklers
  else if (resp == 1)
    desligarSprinklers();

    ....
*/  	
  // Aguarda 0,1s para repetir a leitura
  delay(100);
}
