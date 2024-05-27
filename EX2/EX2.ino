// Declaração das variaveis / numeros reais
float sal, perc, aumento, novosal;

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

  Serial.print("Digite o porcentual: ");
  perc = aguardaEntrada();
  Serial.println(perc);

  aumento = sal * perc/100;

  Serial.print("O valor do aumento: ");
  Serial.println(aumento);

  novosal = sal + aumento;

  delay(3000);

    
  Serial.print("Valor do novo salario: ");
  Serial.println(novosal);

}

// Criando uma função chamada "aguarda entrada"
float aguardaEntrada(){
  while (!Serial.available()){
    // Aguarda até que um valor seja digitado
  }
  // Retornar o valor digitado no serial em tipo float
  return Serial.parseFloat();
}