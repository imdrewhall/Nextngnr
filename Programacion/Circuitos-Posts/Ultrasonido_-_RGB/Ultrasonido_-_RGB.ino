// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  16//15//8 //15//D8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     17//13//7 //13 //D7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


int LedR = 27;//0;  // pin Rojo del led RGB
int LedA = 25;//5;  // pin Verde del led RGB
int LedV = 26;//4;   // pin Azul del led RGB
int distance;
byte y;
volatile int x = 0;



NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 9600 baud to see ping results.
  pinMode(LedR, OUTPUT);    // pone el pinLedR como output
  pinMode(LedV, OUTPUT);    // pone el pinLedV como output
  pinMode(LedA, OUTPUT);    // pone el pinLedA como output
}





void loop() {
  
  delay(500);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.0  Serial.print("Porcentaje: ");
 
  y=sonar.ping_cm()*100/50;
  
  Serial.print(y); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.print("%");
 
  distance= sonar.ping_cm();
  Serial.print("  ");
  Serial.print("distance:");
  Serial.print(" ");
  Serial.print(distance);
  Serial.println("cm");
  if(distance<=3){
     digitalWrite(LedV, LOW);
     digitalWrite(LedR, LOW);
     digitalWrite(LedA, HIGH);
     // azul
  }    
  else if(distance >=25){
     digitalWrite(LedR, HIGH);
     digitalWrite(LedV, HIGH);
     digitalWrite(LedA, HIGH);
     //   magenta
    }
  distance= map (distance,3,25,1,6);
  
  switch (distance){
    case 1: 
     digitalWrite(LedV, LOW);
     digitalWrite(LedR, LOW);
     digitalWrite(LedA, HIGH);
     // Azul
      break;
    
    case 2: 
      digitalWrite(LedV, HIGH);
      digitalWrite(LedR, LOW);
      digitalWrite(LedA, HIGH);
      // aqua
      break;
          
    case 3: 
     digitalWrite(LedV, HIGH);
     digitalWrite(LedR, LOW);
     digitalWrite(LedA, LOW);
     // verde
      break;
  
    case 4: 
      digitalWrite(LedV, HIGH);
      digitalWrite(LedR, HIGH);
      digitalWrite(LedA, LOW);
      // amarillo
      break;
    case 5: 
      digitalWrite(LedV, LOW);
      digitalWrite(LedA, LOW);
      digitalWrite(LedR, HIGH);
      // ROJO
      break;
    case 6:
      digitalWrite(LedR, HIGH);
      digitalWrite(LedV, LOW);
      digitalWrite(LedA, HIGH);
     //   magenta
     }

 } 
 
  
