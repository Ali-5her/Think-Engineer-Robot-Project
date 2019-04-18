#include<Servo.h>//servo library
Servo myservo;//create servo object to control servo
int Echo=A4;
int Trig=A5;
int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
int ABS=150;
int rightDistance=0,leftDistance=0,middleDistance=0;
void_mForward()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
   digitalWrite(in1,HIGH);//digital output
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,HIGH);
   Serial.printIn("go forward!");
}

void_mBack()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
   Serial.printIn("go back!")
}

void_mleft()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
  Serial.printIn("go left!")
}

void_mright()
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
 Serial.printIn("go right!");
}
void_mStop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.printIn("Stop!");
}
 /*Ultrasonic distance measurement Sub function*/
int Distance_test()
{
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig,LOW);
  float Fdistance=pulseIn(Echo,HIGH);
  Fdistance=Fdistance/58;
  return (int)Fdistance;
}

void setup()
{
  myservo.attach(3);//attach servo on pin 3 to servo object
  Serial.begin(9600);
  pinMode(Echo,INPUT);
  pinMode(Trig,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
}

void loop()
{
    my servo.write(90);//setservo position according to scaled value
    delay(500);
    middleDistance=Distance_test();
    #ifdef send
    Serial.print("middleDistance=");
    Serial.printIn(middleDistance;
    #endif

    if(middleDistance<=20)
    {
       _mStop();
       delay(500);
       myservo.write(5);
       delay(1000);
       rightDistance=Distance_test();

       #ifdef send
       Serial.print("rightDistance=");
       Serial.printIn(rightDistance);
       #endif

       delay(500);
        myservo.write(90);
       delay(1000);
       myservo.write(180);
       delay(1000);
       leftDistance=Distance_test();

       #ifdef send
       Serial.print("leftDistance=");
       Serial.printIn(leftDistance);
       #endif

       delay(500);
       myservo.write(90);
       delay(1000);
       if(rightDistance>leftDistance)
        {
          _mright();
          delay(360);
        }
         else if(rightDistance<leftDistance)
         {
          _mleft();
          delay(360);
         }
          else if((rightDistance<=20)||(leftDistance<=20))
          {
            _mBack();
            delay(180);
          }
          else
          {
            _mForward();
          }
         }
         else
              _mForward();
}
        }
       
       
      
    }
  
  
 
}
