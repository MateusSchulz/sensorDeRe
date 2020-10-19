//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos
#define TRIGGER 4
#define ECHO 5
#define BUZZER 6
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(TRIGGER, ECHO);
 
void setup(){
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}
 
void loop(){

  float cmMsec, inMsec, frequency;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  frequency = map(cmMsec, 5, 100, 0, 2000);
  if(frequency < 0) frequency=0;
  if(frequency > 2000) frequency=2000;
  
  Serial.print("F: ");
  Serial.print(frequency);
  Serial.print(" D: ");
  Serial.print(cmMsec);
  Serial.println();
  
  tone(BUZZER, 261.5, 100);
  delay(frequency+100);
  noTone(BUZZER);
}
