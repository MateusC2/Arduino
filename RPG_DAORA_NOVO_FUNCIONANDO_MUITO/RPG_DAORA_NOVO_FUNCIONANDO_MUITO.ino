#define pinHeroiLED 5  //Led seleção do personagem HEROI
#define pinVilaoLED 6  //Led seleção do personagem VILÃO
#define ledvermelho 3  //Led errou ataque
#define ledverde 4     //Led ataque normal
#define ledamarelo 2   //Led ataque critico
#define buzzer 10      //Buzzer para som dos ataques
#define pinoHeroi 8    //Pino para selecionar o heroi
#define pinoVillian 7  //Pino para selecionar o vilão

// Pino para o botão que será pressionado para rolar o dado
#define pinBotao 9  //Botão para começar o jogo e para a rolagem d

//Estados dos botoes
bool estadoBotao = false;           // Estado atual do botão
bool estadoBotao_anterior = false;  // Estado anterior do botão


// Variavel para definição de turno
bool turnoHeroi = false;
bool turnoVilao = false;

// Variável para armazenar o resultado do dado
int resultadoDado;

//variaveis de vida
int vidaVilao = 30;
int vidaHeroi = 30;

//variavel de decisão de turnos
bool turnosOn = false;
bool gamestatus = false;
bool comeco = true;

void setup() {
  // Inicialização dos pinos
  //Leds
  pinMode(pinHeroiLED, OUTPUT);
  pinMode(pinVilaoLED, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarelo, OUTPUT);
  //Buzzer
  pinMode(buzzer, OUTPUT);
  //Botão
  pinMode(pinBotao, INPUT);
  pinMode(pinoHeroi, INPUT);
  pinMode(pinoVillian, INPUT);

  // Inicialização da comunicação serial para debug
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  if (comeco == true) {
    inicio();
  }
  //__________________________________
  fim();
  //__________________________________
  if (turnosOn) {  //dividir quais são os botoes
    estadoBotao = digitalRead(pinBotao);
    if (estadoBotao == HIGH && estadoBotao_anterior == LOW) {
      while (digitalRead(pinBotao) == HIGH) {
        resultadoDado = random(1, 21);  // Gera um número aleatório entre 1 e 20
        Serial.print("Resultado do dado: ");
        delay(800);
        Serial.println(resultadoDado);
        delay(1000);
        if (resultadoDado % 2 == 0) {
          // É par, é o turno do herói
          digitalWrite(pinHeroiLED, HIGH);
          digitalWrite(pinVilaoLED, LOW);
          Serial.println("");
          Serial.println("Turno do heroi!");
          turnoHeroi = true;
          delay(2000);
          digitalWrite(pinHeroiLED, LOW);
          Serial.println("Gire o dado novamente para atacar o VILAO!! \n");
        } else {
          // É ímpar, é o turno do vilão
          digitalWrite(pinHeroiLED, LOW);
          digitalWrite(pinVilaoLED, HIGH);
          Serial.println("");
          Serial.println("Turno do vilao!");
          turnoVilao = true;
          delay(2000);
          digitalWrite(pinVilaoLED, LOW);
          Serial.println("Gire o dado novamente para atacar o HEROI!! \n");
        }
        // Aguarda um tempo para evitar leituras rápidas  do botão
        delay(1000);
        turnosOn = false;
      }
    }
  }  // fim dos turnos_______________________________________________________________________________
  if (estadoBotao == HIGH && estadoBotao_anterior == LOW) {
    while (digitalRead(pinBotao) == HIGH) {
      if (turnoHeroi) {
        ataques();
      }
    }
    while (digitalRead(pinBotao) == HIGH) {
      if (turnoVilao) {
        ataqueVilao();
      }
    }
  }
}

//condições de ataque heroi_____________________________________________________
void ataques() {
  resultadoDado = random(1, 21);  // Gera um número aleatório entre 1 e 20
  Serial.print("Resultado do dado: ");
  delay(800);
  Serial.println(resultadoDado);
  delay(1000);
  if (resultadoDado <= 10) {
    digitalWrite(ledvermelho, HIGH);
    tone(buzzer, 495);
    Serial.println("ERROU O ATAQUE");
    Serial.println("");
    turnoHeroi = false;
    delay(1500);
    digitalWrite(ledvermelho, LOW);
    noTone(buzzer);
    resultadoDado = 0;
  }
  if (resultadoDado > 10) {
    if (resultadoDado < 17) {
      digitalWrite(ledverde, HIGH);
      tone(buzzer, 392);
      Serial.println("Acertou!!");
      delay(1500);
      digitalWrite(ledverde, LOW);
      noTone(buzzer);
      vidaVilao -= resultadoDado;
      Serial.print("Dano causado: ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Vilao: ");
      Serial.println(vidaVilao);
      Serial.println("");
      delay(1000);
      turnoHeroi = false;
    }
    if (resultadoDado >= 17) {
      digitalWrite(ledamarelo, HIGH);
      tone(buzzer, 261);
      Serial.println("ACERTO CRITICO!!");
      delay(1500);
      digitalWrite(ledamarelo, LOW);
      noTone(buzzer);
      resultadoDado = resultadoDado * 2;
      vidaVilao -= resultadoDado;
      Serial.print("Dano causado : ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Vilao: ");
      Serial.println(vidaVilao);
      Serial.println("");
      delay(1000);
      turnoHeroi = false;
    }
  }
  //TROCA DE TURNO
  if (vidaVilao > 1) {
    Serial.println("Turno Vilao");
    Serial.println("Aperte o botao para rolar o DADO!");
    resultadoDado = 0;
    turnoVilao = true;
  }
}


void ataqueVilao() {
  resultadoDado = random(1, 21);  // Gera um número aleatório entre 1 e 20
  Serial.print("Resultado do dado: ");
  delay(800);
  Serial.println(resultadoDado);
  delay(1000);
  if (resultadoDado <= 10) {
    digitalWrite(ledvermelho, HIGH);
    tone(buzzer, 495);
    Serial.println("ERROU O ATAQUE");
    Serial.println("");
    turnoVilao = false;
    delay(1500);
    digitalWrite(ledvermelho, LOW);
    noTone(buzzer);
    resultadoDado = 0;
  }
  if (resultadoDado > 10) {
    if (resultadoDado < 17) {
      digitalWrite(ledverde, HIGH);
      tone(buzzer, 392);
      Serial.println("Acertou!!");
      delay(1500);
      digitalWrite(ledverde, LOW);
      noTone(buzzer);
      vidaHeroi -= resultadoDado;
      Serial.print("Dano causado: ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Heroi: ");
      Serial.println(vidaHeroi);
      Serial.println("");
      delay(1000);
      turnoVilao = false;
    }
    if (resultadoDado >= 17) {
      digitalWrite(ledamarelo, HIGH);
      tone(buzzer, 261);
      Serial.println("ACERTO CRITICO!!");
      delay(1500);
      digitalWrite(ledamarelo, LOW);
      noTone(buzzer);
      resultadoDado = resultadoDado * 2;
      vidaHeroi -= resultadoDado;
      Serial.print("Dano causado : ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Heroi: ");
      Serial.println(vidaHeroi);
      Serial.println("");
      delay(1000);
      turnoVilao = false;
    }
  }
  //TROCA DE TURNO
  if (vidaHeroi > 1) {
    Serial.println("Turno Heroi");
    Serial.println("Aperte o botao para rolar o DADO!");
    resultadoDado = 0;
    turnoHeroi = true;
  }
}

void fim() {
  if (vidaHeroi <= 0) {
    Serial.println("Fim de jogo!!!");
    Serial.println("O vilao GANHOUU");
    digitalWrite(pinVilaoLED, HIGH);
    while (true) {
      // Nada será executado além deste loop infinito
    }
  }
  if (vidaVilao <= 0) {
    Serial.println("Fim de jogo!!!");
    Serial.println("O heroi GANHOUU");
    digitalWrite(pinHeroiLED, HIGH);
    while (true) {
      // Nada será executado além deste loop infinito
    }
  }
}

void inicio() {
  if (digitalRead(pinBotao) == 1 && comeco == true) {
    digitalWrite(ledamarelo, HIGH);
    Serial.println("Bem vindo ao RPG DUEL!!!");
    delay(600);
    Serial.println("Escolhe o seu personagem!");
    delay(300);
    Serial.println("Aperte o Botao 1 Para heroi ou Botao 2 para Vilao \n");
    delay(1500);
    digitalWrite(ledamarelo, LOW);
    gamestatus = true;
  }
  while (gamestatus == true) {

    if (digitalRead(pinoHeroi) == 1) {
      digitalWrite(pinHeroiLED, HIGH);
      Serial.println("HEROIIII!!!");
      Serial.println("Se o numero do dado for PAR o HEROI começa atacando!! \n");
      Serial.println("Se o numero do dado for Impar o VILAO começa atacando!!");
      Serial.println("Aperte o botao para iniciar \n");
      delay(2000);
      digitalWrite(pinHeroiLED, LOW);
      gamestatus = false;
      turnosOn = true;
      comeco = false;
    }

    if (digitalRead(pinoVillian) == 1) {
      digitalWrite(pinVilaoLED, HIGH);
      Serial.println("VILAAOOOO!!! \n");
      Serial.println("Se o numero do dado for PAR o HEROI começa atacando!!");
      Serial.println("Se o numero do dado for Impar o VILAO começa atacando!!\n");
      delay(1500);
      Serial.println("Aperte o botao para iniciar");
      delay(2000);
      digitalWrite(pinVilaoLED, LOW);
      gamestatus = false;
      turnosOn = true;
      comeco = false;
    }
  }
}
