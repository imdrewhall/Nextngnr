

int Min=05; //Cambiar este dato para la hora
int Seg=59; //Cambiar este dato para los min
byte Digit[10][7]=
{ //a b c d e f g
{1,1,1,1,1,1,0}, //0
{0,1,1,0,0,0,0}, //1
{1,1,0,1,1,0,1}, //2
{1,1,1,1,0,0,1}, //3
{0,1,1,0,0,1,1}, //4
{1,0,1,1,0,1,1}, //5
{1,0,1,1,1,1,1}, //6
{1,1,1,0,0,0,0}, //7
{1,1,1,1,1,1,1}, //8
{1,1,1,1,0,1,1} //9
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {

 
for(int i=2;i<=13;i++)
{
pinMode(i,OUTPUT);
}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
int n = millis() / 100 ; // Lo pasamos a segundos
int segundos = n % 60 ;
int minutos = n / 60 ;

int k = minutos * 100 - segundos;
k=k+(Min*100)+Seg;
CalculaDigitos(k) ;


}
void Display(int pos,int N)
{
digitalWrite(9 ,HIGH); // Apaga todos los digitos
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
for (int j=0;j<=6;j++)
{
int valor=Digit[N][j];
digitalWrite(j+2,valor);

}

digitalWrite(pos+9,LOW);

}

void CalculaDigitos( int Num)
{
int Digit0 = Num %10 ;
int Digit1 = (Num % 100) / 10;
int Digit2 = (Num % 1000) / 100;
int Digit3 = (Num / 1000);

Display(3 , Digit3);
Display(2 , Digit2);
Display(1 , Digit1);
Display(0 , Digit0);

}
