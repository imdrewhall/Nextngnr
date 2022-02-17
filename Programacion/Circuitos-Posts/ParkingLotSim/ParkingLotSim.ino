#include "SPI.h"
#include "MFRC522.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); //Change to (0x27,16,2) for 16x2 LCD.

#define SS_PIN 10
#define RST_PIN 9
//#define LED_PIN 4 
//#define LED_PIN 2

//Sensores infrarrojos
const int sensorPin0 = 14;
const int sPinP1 = 15;
const int sPinP2 = 16;
const int sPinP3 = 17;
const int sPinP4 = 20;
const int sPinP5 = 21;
const int sPinP6 = 4;
const int sPinP7 = 3;

//Valores de saldo en las tarjetas de ingreso
float Tarjeta1 = 26.50;
float Tarjeta2 = 22.00;

unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
float Total = 0;
float Tiempo= 0;
int uno = 1;

//https://naylampmechatronics.com/blog/22_Tutorial-Lector-RFID-RC522.html

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

Servo myservo1; 
int pos = 0; 

Servo myservo2; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  lcd.init();
  lcd.backlight();

  
 // pinMode(4, OUTPUT);
 // pinMode(2, OUTPUT);
  pinMode(sensorPin0 , INPUT);  //definir pin como entrada
  pinMode(sPinP1 , INPUT);
  pinMode(sPinP2 , INPUT);
  pinMode(sPinP3 , INPUT);
  pinMode(sPinP4 , INPUT);
  pinMode(sPinP5 , INPUT);
  pinMode(sPinP6 , INPUT);
  pinMode(sPinP7 , INPUT);

  myservo1.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(5);
  Serial.println("I am waiting for card...");
}

void loop() {
  int v0 = 0;
  int v1 = 0;
  int v2 = 0;
  int v3 = 0;
  int v4 = 0;
  int v5 = 0;
  int v6= 0;
  int v7 = 0;

  myservo1.write(0); 
  myservo2.write(180); 

// LECTURA DE ESTACIONAMIENTOS
  v1 = digitalRead(sPinP1 );
  v2 = digitalRead(sPinP2 );
  v3 = digitalRead(sPinP3 );
  v4 = digitalRead(sPinP4 );
  v5 = digitalRead(sPinP5 );
  v6 = digitalRead(sPinP6 );
  v7 = digitalRead(sPinP7 );

 int value = 0;
 value = v1+v2+v3+v4+v5+v6+v7;
    Serial.println("  ");
    Serial.println(value);
    Serial.print("  v1=");Serial.print(v1);
    Serial.print("  v2=");Serial.print(v2);
    Serial.print("  v3=");Serial.print(v3);
    Serial.print("  v4=");Serial.print(v4);
    Serial.print("  v5=");Serial.print(v5);
    Serial.print("  v6=");Serial.print(v6);
    Serial.print("  v7=");Serial.print(v7);
    Serial.println("  ");

 switch (value){
  case 0:
    Serial.println("No hay Espacios disponibles");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  0 "); 
    break;
  case 1:
    Serial.println("1 Espacio disponible");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  1 ");
    break;

  case 2:
    Serial.println("2 Espacios disponibles");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  2 ");
    break;

  case 3:
    Serial.println("3 Espacios disponibles");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  3 ");
    break;

  case 4:
    Serial.println("4 Espacios disponibles");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  4 ");
    break;
  case 5:
    Serial.println("5 Espacios disponible");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  5 ");
    break;
  case 6:
    Serial.println("6 Espacios disponibles");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  6 ");
    break;

  case 7:
    Serial.println("7 Espacios disponibles");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Estacionamientos ");
    lcd.setCursor(0,1);
    lcd.print("Disponibles:  7 ");
    break;
 }

  
  delay(1000);
  
// LECTURA DE RFID
  // put your main code here, to run repeatedly:
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
      (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
      String(rfid.uid.uidByte[i], HEX) +
      (i != 3 ? ":" : "");
  }

  strID.toUpperCase();
  Serial.print("Tap card key: ");
  Serial.println(strID);
  delay(1000);


//SISTEMA DE COBRO


// Entrada
//PART 1

  if (strID.indexOf("EE:88:E9:AB") >= 0 and Tarjeta1 > 0 and uno == 1) {  //put your own tap card key;
    tiempo1 = millis();
    Serial.println("********************");
    Serial.println("**Bienvenido al Parking**");
    Serial.println("********************");

     lcd.clear();
     lcd.setCursor(0,0);
      lcd.print("Bienvenido al ");
      lcd.setCursor(0,1);
      lcd.print("parking ");
     // delay(2000);
     digitalWrite(4, HIGH);
    
    for (pos = 0; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    delay (4000);
    v0 = digitalRead(sensorPin0 );
    
    if (v0 == LOW) {
      do {
        myservo1.write(80);
      //Serial.println("Detectado obstaculo en 0");
      delay(50);
        v0 = digitalRead(sensorPin0 );
    }while(v0==LOW);
    }
    delay(1000);
    digitalWrite(4, LOW);
    for (pos = 80; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
   }
    uno = 0;
    return;
  }
// Salida
  //PART 2
  else if (strID.indexOf("EE:88:E9:AB") >= 0 and uno == 0) {  //put your own tap card key;
    tiempo2 = millis();
    Total = (tiempo2-tiempo1)*0.0000005;
    Tiempo=(tiempo2-tiempo1)*0.000016667;
    Serial.println("********************");
    Serial.print("Su total a pagar es de: $ ");
    Serial.println(Total);
    Serial.println("********************");
    digitalWrite(4, HIGH);
    Tarjeta1=Tarjeta1-Total;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Su tiempo fue de: ");
    lcd.setCursor(0,1);
    lcd.print(Tiempo);
    lcd.setCursor(13,1);
    lcd.print("min");
    delay(3000);
    lcd.clear();
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("Su total a");
    lcd.setCursor(0,1);
    lcd.print("pagar es: $");
    lcd.setCursor(11,1);
    lcd.print(Total);
    delay(2000);
    lcd.clear();
    Tarjeta1=Tarjeta1-Total;
    lcd.setCursor(0,0);
    lcd.print("Tiene un saldo");
    lcd.setCursor(0,1);
    lcd.print("de: $");
    lcd.setCursor(5,1);
    lcd.print(Tarjeta1);
    delay(2000);
    lcd.clear();
    
    Tarjeta1=Tarjeta1-Total;
    Serial.println("Mantiene un saldo total de $ ");
    Serial.print(Tarjeta1);
    Serial.println(" en su tarjeta");
    Serial.println("********************");

    for (pos = 180; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    delay (4000);
    v0 = digitalRead(sensorPin0 );
    
    if (v0 == LOW) {
      do {
        myservo2.write(90);
      //Serial.println("Detectado obstaculo en 0");
      delay(50);
        v0 = digitalRead(sensorPin0 );
    }while(v0==LOW);
    }
    delay(1000);
    digitalWrite(4, LOW);
    for (pos = 90; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
   }
    uno = 1;
    return;
  }

  
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Registrado");
    lcd.setCursor(0,1);
    lcd.print("O sin saldo");
    Serial.println("****************");
    Serial.println("**Usted no está registrado o no tiene suficiente saldo**");
    Serial.println("****************");
    digitalWrite(2, HIGH);
    delay (3000);
    lcd.clear();
    digitalWrite(2, LOW);
    return;
  }
  }
