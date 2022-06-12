
#define Step  19 //GPIO18----Step of stepper motor driver
#define Dir   18 //GPIO19----Direction of stepper motor driver
#define pulse  21
  int i=0;
  int value = LOW;
void setup() {
  Serial.begin(115200);
  delay(10);
 pinMode(Step, OUTPUT); //Step pin as output
 pinMode(Dir,  OUTPUT); //Direcction pin as output
 pinMode(pulse,  INPUT); //Direcction pin as output
 
 digitalWrite(Step, LOW); // Currently no stepper motor movement
 digitalWrite(Dir, LOW);  
 
}
 
void loop() {
  // Check if a client has connected
 int   cam = digitalRead(21);
 
  // Match the request

  
  if (cam == HIGH)  { //Move 50 steps forward
    digitalWrite(Dir, HIGH); //Rotate stepper motor in clock wise direction
          for( i=1;i<=100;i++){
          digitalWrite(Step, HIGH);
          delay(10);
          digitalWrite(Step, LOW);
          delay(10);}
    value = HIGH;
    delay(1500);
    
    digitalWrite(Dir, LOW); //Rotate stepper motor in anti clock wise direction
          for( i=1;i<=50;i++){
          digitalWrite(Step, HIGH);
          delay(10);
          digitalWrite(Step, LOW);
          delay(10);}
    value = LOW;
  }
  

  


  // Return the response
 
 
 /* if(value == HIGH) {
    Serial.println("Forward");
  } else {
    Serial.println("Backward");
  }*/
}
