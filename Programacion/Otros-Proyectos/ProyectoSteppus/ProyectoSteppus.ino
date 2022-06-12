
// Definimos los pines donde tenemos conectadas las bobinas
#define IN1  15//15
#define IN2  13//16
#define IN3  12//17
#define IN4  14//18
#define pulse  02//8

// Secuencia de pasos (par máximo)
int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

void setup()
{
  // Todos los pines en modo salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(pulse, INPUT);
}



void loop()
{
int x=0;
 if(digitalRead(pulse)==HIGH)
 {
  do
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(5);
    }x++;
  }while(x<64);
 }
 else
 {
   digitalWrite(IN1, paso[0][0]);
 } 
}
