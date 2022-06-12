/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/


#define Step1  2 //GPIO2----Step of stepper motor driver
#define Dir1   4 //GPIO4----Direction of stepper motor driver
#define Step2  18 //GPIO18----Step of stepper motor driver
#define Dir2   19 //GPIO19----Direction of stepper motor driver
#define Step3  22 //GPIO22----Step of stepper motor driver
#define Dir3   23 //GPIO23----Direction of stepper motor driver

int m1;  
int m2;  
int m3;  
int sentido;



int i=0;
int value = LOW;

 
void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
  delay(10);
   pinMode(Step1, OUTPUT); //Step pin as output
   pinMode(Dir1,  OUTPUT); //Direcction pin as output
   pinMode(Step2, OUTPUT); //Step pin as output
   pinMode(Dir2,  OUTPUT); //Direcction pin as output
   pinMode(Step3, OUTPUT); //Step pin as output
   pinMode(Dir3,  OUTPUT); //Direcction pin as output
   
   pinMode(34, INPUT);
   pinMode(35, INPUT);
   pinMode(32, INPUT);
   pinMode(25,  INPUT); //Direcction pin as input
   
   
   digitalWrite(Step1, LOW); // Currently no stepper motor movement
   digitalWrite(Dir1, LOW);  
   digitalWrite(Step2, LOW); // Currently no stepper motor movement
   digitalWrite(Dir2, LOW); 
   digitalWrite(Step3, LOW); // Currently no stepper motor movement
   digitalWrite(Dir3, LOW); 
   digitalWrite(sentido, LOW);

}
 
void loop() {
 int sen = digitalRead(25);
    m1 = digitalRead(34);
    m2 = digitalRead(35);
    m3 = digitalRead(32);
   if(sen == HIGH) {
    if(sentido == HIGH) {
       Serial.println("Forward");
        digitalWrite(Dir1, HIGH);  
        digitalWrite(Dir2, HIGH); 
        digitalWrite(Dir3, HIGH); 
        sentido=LOW;
        delay(1000);
    } else {
       Serial.println("Backward");
        digitalWrite(Dir1, LOW);  
        digitalWrite(Dir2, LOW); 
        digitalWrite(Dir3, LOW); 
        sentido=HIGH;
        delay(1000);
    }
 }
  
      if(m1 == HIGH) {
          digitalWrite(Step1, HIGH);
          delay(10);
          digitalWrite(Step1, LOW);
          delay(10);
      }
      else if(m2 == HIGH) {
          digitalWrite(Step2, HIGH);
          delay(10);
          digitalWrite(Step2, LOW);
          delay(10);
      }
      else if(m3 == HIGH) {
          digitalWrite(Step3, HIGH);
          delay(1);
          digitalWrite(Step3, LOW);
          delay(1);
      }else {
    digitalWrite(Step1, LOW);
    digitalWrite(Step2, LOW);
    digitalWrite(Step3, LOW);
    }
  
}
