/*
 * @author: Robson Rodrigues da silva
 * @Company: Centro universitário Senac - SP
 * 
 * @description: Exemplo de leitura de sensores e visualisação 
 *               dos dados no terminal serial do arduino IDE
 */
 

#define LM35
//#define DS18B20

#define ARDUINO

#ifdef  DS18B20
  #include <OneWire.h>
#endif

#ifdef ARDUINO

  //define a constante tempIn com valor A0
  int tempIn = A0;
  //define a constante tempOut com valor A1
  int tempOut = A1;
  //define a constante mic com valor A2
  int mic    = A2;
#else
  #include <OneWire.h>
#endif


  

  int mic     = A0;
  int tempIn  = D0;
  int tempOut = D1;
#endif

void tempRead();
void micRead();


void setup() {
  //inicia a conexão serial com velocidade 9600 bps
  Serial.begin(9600);
  Serial.println("Iniciando leitura dos sensores");
  
  pinMode(tempIn, INPUT);
  pinMode(tempOut, INPUT);
  pinMode(mic, INPUT);

  #ifdef LM35
      Serial.println("Sensor selecionado: LM35");
  #else
      Serial.println("Sensor selecionado: DS18B20");
  #endif

  float tempIn  = 0;
  float tempOut = 0;
}

void loop() {
   tempRead();
   micRead();
   delay(1000);

}

#ifdef LM35
//função para leitura da temperatura com lm35
void tempRead(){
  Serial.println("Funcao para o sensor M35");
  tempIn = analogRead(tempIn);
  tempOut = analogRead(tempOut);
  Serial.println(tempIn * 0.0048828125 *100);
}
#else
//função para leitura da temperatura com ds18b20
void tempRead(){
  Serial.println("Funcao para o sensor DS18B20");
}
#endif
 

//função para leitura do microfine 
void micRead(){
  Serial.println("Funcao para o sensor de ruido");
}
