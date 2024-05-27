//Constanates que representam os pinos dos componentes
#define button 2
#define ldr A0
#define led 3
#define buzzer 4

//Variavel de controle do estado do botão
bool status = false;

void setup() {
  //Iniciando o serial monitor
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, OUTPUT);
  delay(1000);
}

void loop() {
  // Testando os componentes

  //Teste do Led
  // digitalWrite(led, HIGH);
  // delay(200);
  // digitalWrite(led, LOW);
  // delay(200);
  // digitalWrite(led, HIGH);

  //Teste da buzzer
  // tone(buzzer, 523); //Dó
  // delay(200);
  // noTone(buzzer);
  // delay(200);

  //Teste do button
  // Serial.print("Sinal Botao: ");
  // Serial.println(digitalRead(button));
  // Serial.print("Leitura LDR");
  // Serial.println(analogRead(ldr));
  // Serial.println("-----------------------------");
  // delay(500);

  //Verificar qual a situação de aperto do botão (armar ou desarmar)
  if (digitalRead(button) == 1 && status == false) {
    //O alarme esta desarmado
    status = true;  // atualizando a variavel de controle

  } else if (digitalRead(button) == 1 && status == true) {                                               
    //O alarme esta armado
    status = false;

    //"Piscar" o led e a buzzer por 10 vezes, simbolizando o sinal de desarme do alarme
    for (byte cont = 0; cont < 10;cont++){      //cont++ === cont = cont + 1
    digitalWrite(led, HIGH);
    tone(buzzer, 523);
    delay(200);
    digitalWrite(led, LOW);
    noTone(buzzer);
    delay(200);
    }
  }

  if (status == true) {
    if (analogRead(ldr) < 900) {
      //Acionar o led e a buzzer, caso a luminosidade for baixa
      digitalWrite(led, HIGH);
      tone(buzzer, 523);
    } else {
      //Desativar buzzer/led, caso a luminosidade
      digitalWrite(led, LOW);
      noTone(buzzer);
    }
  } else {
    //Desliga tudo
    digitalWrite(led, LOW);
    noTone(buzzer);
  }
  delay(200);  // Delay estratégico para execução do sistema
}
