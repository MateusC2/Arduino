// constante para pino da buzzer
#define pinoBuzzer 2
#define pinoLedVerm 3

void setup() {
  Serial.begin(9600);
  //modo do pino
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerm, OUTPUT);

  delay(1000);  //parada estrategica
}

void loop() {
  tone(pinoBuzzer, 523);//Nota Musical DÓ
  digitalWrite(pinoLedVerm, HIGH);
  delay(1000);
  noTone(pinoBuzzer);//Desliga o buzzer
  digitalWrite(pinoLedVerm, HIGH); //apaga o led
  delay(1000);
}
