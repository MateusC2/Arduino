//Constantes para armazenamento dos pinos trig e echo
#define pinoTrig 2
#define pinoEcho 3
#define pinoLed 4

//Variavel para guardar o tempo da onda
float tempoEcho = 0.0;

//Valores baseados na velocidade do som
float velocidadeSom = 340;         // metros por segundo
float velocidadeSomms = 0.000340;  //metros por microsegundos
void setup() {
  Serial.begin(9600);

  //Configuração do pino Trigger como saída e inicialização com sina LOW
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoLed, OUTPUT);
  digitalWrite(pinoTrig, LOW);
  delay(1000);

  //Configuração do pino echo como entrada
  pinMode(pinoEcho, INPUT);
}

void loop() {
  //Envia pulso para disparar o sensor
  disparaUltrassonico();

//Mede o tempo de duração do sinal do pino de leitura(em microsegundos)
  tempoEcho=pulseIn(pinoEcho, HIGH);

  Serial.print("Distancia em metros: ");
  Serial.println(calculaDistancia(tempoEcho));
  Serial.print("Distancia em cm: ");
  Serial.println(calculaDistancia(tempoEcho) * 100);
  delay(500);

if (calculaDistancia((tempoEcho) * 100) < 5){
    digitalWrite(pinoLed, HIGH);
    delay(300);
    digitalWrite(pinoLed, LOW);
  }
if (calculaDistancia((tempoEcho) * 100) > 6){
    digitalWrite(pinoLed, LOW);
  }
}

//Função para acionar o ultrassonico (pulso trigger)
void disparaUltrassonico(){
//Para fazer o ultrassonico enviar um pulso é necessario enviar para o pino trigger um sinal HIGH, com pelo menos 10us(Microsegundos) de duração
digitalWrite(pinoTrig, HIGH); //aciona o pino Trigger
delayMicroseconds(10); // Tempo de leitura
digitalWrite(pinoTrig, LOW); //Desativa o Trigger
}

//Função para calcular a distancia em metros 
float calculaDistancia(float tempoMicros){
return ((tempoMicros * velocidadeSomms)/2);
}