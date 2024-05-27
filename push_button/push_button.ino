// declaração da constante que armazena o pino do Push Button nhaaaaaa
#define pinoButton 8

//delclaração da variavel de estado do botão
bool status = false;

int led = 4;

void setup() {

  
  // definir a modalidade do pino
  pinMode(4, OUTPUT);

  pinMode(pinoButton, INPUT);

  Serial.begin(9600);

  delay(1000);  // a paradinhaaaa, a pardinha a a a a
}

void loop() {
  //  lendo o pino digitavel através da constante
  //Serial.println(digitalRead(pinoButton));

  if (digitalRead(pinoButton) == 1 && status == false){
    digitalWrite(4, HIGH);
    Serial.println("Led ligado!");
    status = true;
  
  } 
  else if (digitalRead(pinoButton) == 1 && status == true) {
    digitalWrite(4, LOW);
    Serial.println("Led desligado!");
    status = false;
  }

  delay(500);  //a paradinhaaaaa, a paradinha a a a a
}
