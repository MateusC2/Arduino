//Definição das contastantes:Pino de entrada
#define pinoBuzzer 2
#define pinoDo 3
#define pinoRe 4
#define pinoMi 5
#define pinoFa 6
#define pinoSo 7
#define pinoLa 8
#define pinoSi 9
#define pinoDoo 10
byte doh, re, mi , fa, so, la ,si ,doo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoDo, INPUT);
  pinMode(pinoRe, INPUT);
  pinMode(pinoMi, INPUT);
  pinMode(pinoFa, INPUT);
  pinMode(pinoSo, INPUT);
  pinMode(pinoLa, INPUT);
  pinMode(pinoSi, INPUT);
  pinMode(pinoDoo, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  //Leitura dos botoes armazenada nas variaveis de controle
  doh = digitalRead(pinoDo);
  re = digitalRead(pinoRe);
  mi = digitalRead(pinoMi);
  fa = digitalRead(pinoFa);
  so = digitalRead(pinoSo);
  la = digitalRead(pinoLa);
  si = digitalRead(pinoSi);
  doo = digitalRead(pinoDoo);

  //Verificando qual nota foi acionada
  if(doh == 1){
    //Ativa a nota dó
    tone(pinoBuzzer, 262);
  }
  else if(re == 1){
  //Ativa a note Re
  tone(pinoBuzzer, 294);
}
 else if(mi == 1){
  //Ativa a note Mi
  tone(pinoBuzzer, 330);
}
 else if(fa == 1){
  //Ativa a note Fa
  tone(pinoBuzzer, 349);
}
 else if(so == 1){
  //Ativa a note So
  tone(pinoBuzzer, 392);
}
 else if(la == 1){
  //Ativa a note La
  tone(pinoBuzzer, 440);
}
 else if(si == 1){
  //Ativa a note Si
  tone(pinoBuzzer, 494);
}
 else if(doo == 1){
  //Ativa a note #Do
  tone(pinoBuzzer, 528);
}
  else{
  noTone(pinoBuzzer);
  }
  delay(50);
}
