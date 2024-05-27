// constante para pino da buzzer
#define pinoBuzzer 4
#define pinoLedVerm 3
#define pinoButton 2
#define pinoButton2 5

void setup() {
  Serial.begin(9600);
  //modo do pino
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerm, OUTPUT);
  pinMode(pinoButton, INPUT);

  delay(1000);  //parada estrategica
}

void loop() {
  if (digitalRead(pinoButton) == 1){
    tone(pinoBuzzer, 523);  //Nota Musical DÓ
    digitalWrite(pinoLedVerm, HIGH);
  }
  
  else if (digitalRead(pinoButton) == 0) {
  noTone(pinoBuzzer);               //Desliga o buzzer
  digitalWrite(pinoLedVerm, LOW);  //apaga o led
  }
}
