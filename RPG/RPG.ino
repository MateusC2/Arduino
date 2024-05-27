// constante para pino da buzzer
#define pinoBuzzer 4
#define pinoLedAma 3
#define pinoButton 2
#define pinoHeroi 5
#define pinoVillian 6
#define pinoLedVerm 7
#define pinoLedVerd 8
bool gamestatus = false;

void setup() {
  Serial.begin(9600);
  //modo do pino
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLedVerm, OUTPUT);
  pinMode(pinoLedVerd, OUTPUT);
  pinMode(pinoLedAma, OUTPUT);
  pinMode(pinoButton, INPUT);
  pinMode(pinoHeroi, INPUT);
  pinMode(pinoVillian, INPUT);

  delay(1000);  //parada estrategica
}

void loop() {
  if (digitalRead(pinoButton) == 1) {
    digitalWrite(pinoLedAma, HIGH);
    Serial.println("Bem vindo ao RPG DUEL!!!");
    Serial.println("Escolhe a porra do boneco");
    Serial.println("1 Para heroi, 2 para Vilao");
    Serial.print(gamestatus);
    delay(4000);
    digitalWrite(pinoLedAma, LOW);
    gamestatus = true;
    Serial.println(gamestatus);
  }
  while (gamestatus == true) {

    if (digitalRead(pinoHeroi) == 1) {
      digitalWrite(pinoLedVerd, HIGH);
      Serial.println("HEROIIII!!!");
      delay(2000);
      digitalWrite(pinoLedVerd, LOW);
    }
    
    if (digitalRead(pinoVillian) == 1) {
      digitalWrite(pinoLedVerm, HIGH);
      Serial.println("VILAAOOOO!!!");
      delay(2000);
      digitalWrite(pinoLedVerm, LOW);
    }
  }
}
