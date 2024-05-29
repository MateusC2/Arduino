// Definição dos pinos para os LEDs representando o herói e o vilão
#define pinHeroiLED 5
#define pinVilaoLED 4

// Pino para o botão que será pressionado para rolar o dado
int pinBotao = 8;
bool estadoBotao = false;           // Estado atual do botão
bool estadoBotao_anterior = false;  // Estado anterior do botão


// Variavel para definição de turno
bool turnoHeroi = false;
bool turnoVilao = false;

// Variável para armazenar o resultado do dado
int resultadoDado;

//variaveis de vida
int vidaVilao = 100;
int vidaHeroi = 100;

//variavel de decisão de turnos
bool turnosOn = true;

void setup() {
  // Inicialização dos pinos
  pinMode(pinHeroiLED, OUTPUT);
  pinMode(pinVilaoLED, OUTPUT);
  pinMode(pinBotao, INPUT);

  // Inicialização da comunicação serial para debug
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  //programaçao anterior para iniciar
  //_______________________________________________________________________________________________
  fim ();
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
          Serial.println("Turno do heroi!");
          turnoHeroi = true;
          delay(2000);
          digitalWrite(pinHeroiLED, LOW);
          Serial.println("Gire o dado novamente para atacar o VILAO!!");
        } else {
          // É ímpar, é o turno do vilão
          digitalWrite(pinHeroiLED, LOW);
          digitalWrite(pinVilaoLED, HIGH);
          Serial.println("Turno do vilao!");
          turnoVilao = true;
          delay(2000);
          digitalWrite(pinVilaoLED, LOW);
          Serial.println("Gire o dado novamente para atacar o HEROI!!");
        }
        // Aguarda um tempo para evitar leituras rápidas do botão
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
    Serial.println("ERROU O ATAQUE");
    turnoHeroi = false;
    delay(1000);
    resultadoDado = 0;
  }
  if (resultadoDado > 10) {
    if (resultadoDado < 17) {
      Serial.println("Acertou!!");
      vidaVilao -= resultadoDado;
      Serial.print("Dano causado: ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Vilao: ");
      Serial.println(vidaVilao);
      delay(1000);
      turnoHeroi = false;
    }
    if (resultadoDado >= 17) {
      Serial.println("ACERTO CRITICO!!");
      resultadoDado = resultadoDado * 2;
      vidaVilao -= resultadoDado;
      Serial.print("Dano causado : ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Vilao: ");
      Serial.println(vidaVilao);
      delay(1000);
      turnoHeroi = false;
    }
  }
  //TROCA DE TURNO
  Serial.println("Turno Vilao");
  Serial.println("Aperte o botao para rolar o DADO!");
  resultadoDado = 0;
  turnoVilao = true;
  if (estadoBotao == HIGH && estadoBotao_anterior == LOW) {
    while (digitalRead(pinBotao) == HIGH) {
    }
  }
}


void ataqueVilao() {
  resultadoDado = random(1, 21);  // Gera um número aleatório entre 1 e 20
  Serial.print("Resultado do dado: ");
  delay(800);
  Serial.println(resultadoDado);
  delay(1000);
  if (resultadoDado <= 10) {
    Serial.println("ERROU O ATAQUE");
    turnoVilao = false;
    delay(1000);
    resultadoDado = 0;
  }
  if (resultadoDado > 10) {
    if (resultadoDado < 17) {
      Serial.println("Acertou!!");
      vidaHeroi -= resultadoDado;
      Serial.print("Dano causado: ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Heroi: ");
      Serial.println(vidaHeroi);
      delay(1000);
      turnoVilao = false;
    }
    if (resultadoDado >= 17) {
      Serial.println("ACERTO CRITICO!!");
      resultadoDado = resultadoDado * 2;
      vidaHeroi -= resultadoDado;
      Serial.print("Dano causado : ");
      Serial.println(resultadoDado);
      delay(1500);
      Serial.print("VIDA ATUAL DO Heroi: ");
      Serial.println(vidaHeroi);
      delay(1000);
      turnoVilao = false;
    }
  }
  //TROCA DE TURNO
  Serial.println("Turno Heroi");
  Serial.println("Aperte o botao para rolar o DADO!");
  resultadoDado = 0;
  turnoHeroi = true;
  if (estadoBotao == HIGH && estadoBotao_anterior == LOW) {
      while (digitalRead(pinBotao) == HIGH) {
      }
    }
  }

void fim(){
 if (vidaHeroi <= 0){
  Serial.println("Fim de jogo!!!");
  Serial.println("O vilao GANHOUU");
   while (true) {
    // Nada será executado além deste loop infinito
  }
 }
  if (vidaVilao <= 0){
  Serial.println("Fim de jogo!!!");
  Serial.println("O heroi GANHOUU");
   while (true) {
    // Nada será executado além deste loop infinito
  }
 }
}