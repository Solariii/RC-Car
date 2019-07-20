#include <SoftwareSerial.h>
#define mRP 2 // Right Postive
#define mRN 4 // Right Negative
#define mLP 7 // Left Postive
#define mLN 8 // Left Negative

void forward()
{
digitalWrite(mRP, LOW);
digitalWrite(mRN, LOW);
digitalWrite(mLP, HIGH);
digitalWrite(mLN, HIGH);
 for(int i=0;i<255;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(13,HIGH);
}

void backward()
{
digitalWrite(mRP, LOW);
digitalWrite(mRN, HIGH);
digitalWrite(mLP, LOW);
digitalWrite(mLN, HIGH);
 for(int i=0;i<255;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(13,HIGH);
}

void Stop()
{
digitalWrite(mRP, LOW);
digitalWrite(mRN, LOW);
digitalWrite(mLP, LOW);
digitalWrite(mLN, LOW);
}
void SlightRight()
{ 
  digitalWrite (mRP,HIGH);
  digitalWrite(mRN, LOW);
  digitalWrite(mLP, LOW);
  digitalWrite(mLN, LOW);
   for(int i=0;i<75;i++)
  {
    analogWrite(9,i);
  }
  digitalWrite(5,HIGH);
  }
void SlightLeft ()
{
  digitalWrite (mRP,LOW);
  digitalWrite(mRN, LOW);
  digitalWrite(mLP, HIGH);
  digitalWrite(mLN, LOW);
   for(int i=0;i<75;i++)
  {
    analogWrite(6,i);
  }
  digitalWrite(12,HIGH);
}
  void Right()
  {
    digitalWrite(mRP,HIGH);
    digitalWrite(mRN, LOW);
    digitalWrite(mLP, LOW);
    digitalWrite(mLN, HIGH);
     for(int i=0;i<150;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(5,HIGH);
    }
   void Left()
   {
    digitalWrite (mRP,LOW);
    digitalWrite(mRN, HIGH);
    digitalWrite(mLP, HIGH);
    digitalWrite(mLN, LOW);
     for(int i=0;i<150;i++)
  {
    analogWrite(6,i);
    analogWrite(9,i);
  }
  digitalWrite(12,HIGH);
    }

int TX = 10;
int RX = 11;
SoftwareSerial bluetooth(TX, RX);
void setup() {
Serial.begin(9600);
bluetooth.begin(9600);
pinMode(mRP, OUTPUT);
pinMode(mRN, OUTPUT);
pinMode(mLP, OUTPUT);
pinMode(mLN, OUTPUT);
pinMode (5,OUTPUT);
pinMode(12,OUTPUT);
pinMode(3,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(13,OUTPUT);
}

void loop() {
  while(bluetooth.available())
{
Serial.println("BLUETOOTH AVAILABLE");
digitalWrite(3,HIGH);
digitalWrite(3,LOW);  
char data = bluetooth.read();
if(data =='1') // forward
{  
Serial.println("Forward");
forward();
}
else if(data =='2') //backward
{
Serial.println("Backward");
backward();

}
else if(data =='0') //stop
{
Serial.println("Stop");
Stop();
}
else if ( data =='3') //SlightRight
{
  Serial.println("Slight Right");
  SlightRight ();
}
else if( data=='4') //Slight Left
{
  Serial.println("Slight Left");
  SlightLeft ();
}
else if (data=='5') //Right
{
  Serial.println ("Right");
  Right ();
  }
else if (data =='6') //Left
{
  Serial.println("Left");
  Left();
}

}
}
