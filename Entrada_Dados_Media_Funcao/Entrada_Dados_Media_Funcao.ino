// Declaração das variaveis / numeros reais
float nota1, nota2, nota3, peso1, peso2, peso3, media;

void setup() {
  //Inicia a comunicação com o serial monitor
  Serial.begin(9600);
  delay(1000);  //Espera estrategica
}

void loop() {
  Serial.print("Digite a nota 1: ");
 
  // Lê o valor da serial e guarda na variavel nota1
  nota1 = aguardaEntrada();
  Serial.println(nota1);
  Serial.print("Digite a nota 2: ");
  
  nota2 = aguardaEntrada();
  Serial.println(nota2);
  Serial.print("Digite a nota 3: ");
 
  nota3 = aguardaEntrada();
  //Atribuição dos pesos
  Serial.println(nota3);
  Serial.print("Digite o peso 1: ");
 
  peso1 = aguardaEntrada();
  Serial.println(peso1);
  //Atribuição dos pesos
  Serial.print("Digite o peso 2: ");
  
  peso2 = aguardaEntrada();
  Serial.println(peso2);
  //Atribuição dos pesos
  Serial.print("Digite o peso 3: ");
  
  peso3 = aguardaEntrada();
  Serial.println(peso3);
  //Calculo da media ponderada:
  media = (nota1 * peso1 + nota2 * peso2 + nota3 * peso3) / (peso1 + peso2 + peso3);

  //Exibe o valor da media calculada
  Serial.print("Resultado da media ponderada: ");
  Serial.println(media);
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
