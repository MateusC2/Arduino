// Declaração das variaveis / numeros reais
float sal, salreceber, grat, imp;

void setup() {
  //Inicia a comunicação com o serial monitor
  Serial.begin(9600);
  delay(1000);  //Espera estrategica
}

void loop() {
  Serial.print("Digite o valor do salario: ");
 

  sal = aguardaEntrada();
  Serial.println(sal);

  grat = sal * 5/100;
  imp = sal * 7/100;
  salreceber = sal + grat - imp;

  delay(3000);

    
  Serial.print("Salario a receber: ");
  Serial.println(salreceber);

}

// Criando uma função chamada "aguarda entrada"
float aguardaEntrada(){
  while (!Serial.available()){
    // Aguarda até que um valor seja digitado
  }
  // Retornar o valor digitado no serial em tipo float
  return Serial.parseFloat();
}