/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

const int pinA = 27;
const int pinB = 32;
const int pinC = 21;
const int pinD = 18;
const int pinE = 5;
const int pinF = 26;
const int pinG = 22;
const int De1 = 14;
const int De2 = 25;
const int De3 = 33;
const int De4 = 23;
int x;
int y;
// the setup routine runs once when you press reset:

byte Digit[16][7]=
{ //a b c d e f g
{0,0,0,0,0,0,1}, //0
//{0,1,1,0,0,0,0}
  {1,0,0,1,1,1,1},//1
  
//{1,1,0,1,1,0,1}
  {0,0,1,0,0,1,0},//2
  
//{1,1,1,1,0,0,1}
  {0,0,0,0,1,1,0},//3
  
//{0,1,1,0,0,1,1}
  {1,0,0,1,1,0,0},//4
  
//{1,0,1,1,0,1,1}
  {0,1,0,0,1,0,0},//5
  
//{1,0,1,1,1,1,1}
  {0,1,0,0,0,0,0},//6
  
//{1,1,1,0,0,0,0}
  {0,0,0,1,1,1,1},//7

//{1,1,1,1,1,1,1},
  {0,0,0,0,0,0,0},//8

//{1,1,1,1,0,1,1}
  {0,0,0,0,1,0,0},//9
  {0,1,1,1,1,1,1},
  {1,0,1,1,1,1,1},
  {1,1,0,1,1,1,1},
  {1,1,1,0,1,1,1},
  {1,1,1,1,0,1,1},
  {1,1,1,1,1,0,1},
};
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(De1, OUTPUT);  
  pinMode(De2, OUTPUT);  
  pinMode(De3, OUTPUT);  
  pinMode(De4, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
for (int i = 0; i < 500; i++)////LETS
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0
  digitalWrite(pinA, HIGH);   // L
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);     
  delay(1);                   // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, LOW);   //E
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, LOW);   //T
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);      
  delay(1);               // wait for a second

  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, LOW);   // S
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1);               // wait for a second
};
for (int i = 0; i < 500; i++)//// GO 1
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0
  digitalWrite(pinA, LOW);    ///G
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, LOW);   //O
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
  delay(1);               // PRIMER STOP
  };
 for (int i = 0; i < 500; i++)//// GO 2
 {
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
   
  digitalWrite(pinA, LOW);    ///G
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1); 
     
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, LOW);    //O
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);     
  delay(1);               // SEGUNDO STOP
};
 for(int i = 0; i <500; i++) 
 {
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, LOW);    ///G
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);    
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, LOW);   //O
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH); 
  delay(1);               // wait for a second
  
};

delay(150);
  digitalWrite(De1, HIGH);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, HIGH); 
  //Todos encendidos

for(int a=9; a!=-1; a--)
  {
  digitalWrite(pinA, Digit[a][0]);   
  digitalWrite(pinB, Digit[a][1]);   
  digitalWrite(pinC, Digit[a][2]);   
  digitalWrite(pinD, Digit[a][3]);   
  digitalWrite(pinE, Digit[a][4]);   
  digitalWrite(pinF, Digit[a][5]);   
  digitalWrite(pinG, Digit[a][6]);
  delay(500);    
  };
  delay(200);
for (int b = 0; b < 500; b++)//bY
 {
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, HIGH);    /// b
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);    
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, HIGH);  //Y 
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);      
  delay(1);               // wait for a second
  // wait for a second
};


for (int i = 0; i < 500; i++)//// GO 1
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0
  digitalWrite(pinA, HIGH);    // U
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
  delay(1);             // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, LOW);   // S
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1);           // PRIMER STOP
  };
 for (int i = 0; i < 500; i++)//// GO 2
 {
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
   
  digitalWrite(pinA, HIGH);    // U
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
  delay(1); 
     
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, LOW);   // S
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1);         // SEGUNDO STOP
};
 for(int i = 0; i <500; i++) 
 {
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, HIGH);    // U
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
  delay(1);    
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, LOW);   // S
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1);  
};
/*
for (int i = 0; i < 500; i++) //NEXT
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0
  digitalWrite(pinA, LOW);   //N
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, LOW);   //E
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);  
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW); 
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, HIGH);   //H - X
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);      
  delay(1);               // wait for a second

  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, LOW);   //T
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);      
  delay(1);               // wait for a second
};
for (int i = 0; i < 500; i++) // NGNR
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0
  digitalWrite(pinA, LOW);   //N
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, LOW);   //G
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);  
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW); 
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, LOW);   //N
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);        
  delay(1);               // wait for a second

  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, LOW);   //R
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);       
  delay(1);               // wait for a second
}
*/
y=15;
x=10;
 for(int u=0; u<3; u++) 
 {
 for(int i=0; i<250; i++) 
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0

  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, HIGH);    /// b
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);    
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, HIGH);  //Y 
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);      
  delay(1);  
      
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, LOW);   //E
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);  
  delay(1); 
 };
 for(int i=0; i<250; i++) 
 {
 digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0

  digitalWrite(pinA, HIGH);    /// b
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);    
  delay(1);               // wait for a second
  

  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, HIGH);  //Y 
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);      
  delay(1);  

   digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, LOW);   //E
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);  
  delay(1); 
  
 };
 };

  for(int i; i<60; i++) 
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0
  digitalWrite(pinA, Digit[x][0]);   
  digitalWrite(pinB, Digit[x][1]);   
  digitalWrite(pinC, Digit[x][2]);   
  digitalWrite(pinD, Digit[x][3]);   
  digitalWrite(pinE, Digit[x][4]);   
  digitalWrite(pinF, Digit[x][5]);   
  digitalWrite(pinG, Digit[x][6]);
  delay(7); 
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
    digitalWrite(pinA, Digit[y][0]);   
  digitalWrite(pinB, Digit[y][1]);   
  digitalWrite(pinC, Digit[y][2]);   
  digitalWrite(pinD, Digit[y][3]);   
  digitalWrite(pinE, Digit[y][4]);   
  digitalWrite(pinF, Digit[y][5]);   
  digitalWrite(pinG, Digit[y][6]);
  delay(7); 
               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
   digitalWrite(pinA, Digit[x][0]);   
  digitalWrite(pinB, Digit[x][1]);   
  digitalWrite(pinC, Digit[x][2]);   
  digitalWrite(pinD, Digit[x][3]);   
  digitalWrite(pinE, Digit[x][4]);   
  digitalWrite(pinF, Digit[x][5]);   
  digitalWrite(pinG, Digit[x][6]);
  delay(7); 
      
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, Digit[y][0]);   
  digitalWrite(pinB, Digit[y][1]);   
  digitalWrite(pinC, Digit[y][2]);   
  digitalWrite(pinD, Digit[y][3]);   
  digitalWrite(pinE, Digit[y][4]);   
  digitalWrite(pinF, Digit[y][5]);   
  digitalWrite(pinG, Digit[y][6]);
  delay(7); 
  y--;
  x++;
  if (x== 16)
  {
    x=10;
    y=15;       
  }
 };
 delay(150);
/*
for (int i = 0; i < 5000; i++) //HALL
 {
  digitalWrite(De1, HIGH);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //0
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, HIGH);
  digitalWrite(De3, LOW);
  digitalWrite(De4, LOW); 
  //1
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);               // wait for a second
  
  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, HIGH);
  digitalWrite(De4, LOW); 
  //2
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);      
  delay(1);               // wait for a second

  digitalWrite(De1, LOW);
  digitalWrite(De2, LOW);
  digitalWrite(De3, LOW);
  digitalWrite(De4, HIGH); 
  //3
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);     
  delay(1);               // wait for a second
};

  // wait for a second
*/
}
