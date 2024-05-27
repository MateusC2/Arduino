// Declaração das variaveis / numeros reais
float sal, novosal;

void setup() {
  //Inicia a comunicação com o serial monitor
  Serial.begin(9600);
  delay(1000);  //Espera estrategica
}

void loop() {
  Serial.print("Digite o valor do salario: ");
 
  // Lê o valor da serial e guarda na variavel nota1
  sal = aguardaEntrada();
  Serial.println(sal);
  
  //Calculo da media ponderada:
  novosal = sal + sal * 25/100;

  Serial.print("O valor do novo salario:");
  
  Serial.println(novosal);
  delay(3000);
}

// Criando uma função chamada "aguarda entrada"
float aguardaEntrada(){
  while (!Serial.available()){
    // Aguarda até que um valor seja digitado
  }
  // Retornar o valor digitado no serial em tipo float
  return Serial.parseFloat();
}