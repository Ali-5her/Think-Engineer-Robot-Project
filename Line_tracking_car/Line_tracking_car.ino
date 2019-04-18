#define WHITE false
#define BLACK true

int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
int ABS=100;

void _mForward()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);//digital output
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}

void _mBack()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}

void _mleft()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  Serial.println("go left!");
}

void _mright()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go right!");
} 
void _mStop()
{
   digitalWrite(ENA,LOW);
   digitalWrite(ENB,LOW);
   Serial.println("Stop!");
} 

void setup() 
{
  Serial.begin(9600);
}

void loop() {
  int left_sensor,middle_sensor,right_sensor;
  left_sensor=digitalRead(10);    
  middle_sensor=digitalRead(4);
  right_sensor=digitalRead(2); 
  Serial.println(left_sensor);
  Serial.println(middle_sensor);
  Serial.println(right_sensor);
   if((left_sensor==WHITE)&&(right_sensor==BLACK)) 
   { 
    Serial.println("going right! RIGHT BLACK");
    _mright();          //The sensor detected that right car turn left immediately when it meets black line 
    delay(2);
    while(1){
      left_sensor=digitalRead(2);         //Cycle to judge degree of intermediate sensor,
      if(left_sensor==WHITE)
      {  
         _mright();                     //If middle_sensor==1 does not go to the middle position, continue to turn left.
         delay(2);
      } else {
         break;                      //Detection of middle_sensor==0 instructions turned over, out of the loop, detection of three sensors’ statusand then make appropriate action
      }
    }                                       //The following and so on
   }else if((left_sensor==BLACK)&&(right_sensor==WHITE)){
     Serial.println("going left! LEFT BLACK");
      _mleft();
      delay(2);
      while(1){
        right_sensor=digitalRead(2);
        if(right_sensor==WHITE){
          _mleft();  
          delay(2);
        } else { 
          break;
        }
      }
   }else if((middle_sensor==BLACK)&&(left_sensor==WHITE)&&(right_sensor==WHITE)){
    Serial.println("going forward! MIDDLE BLACK");
    _mForward();
    delay(2);
  }else if((middle_sensor==BLACK)&&(left_sensor==BLACK)&&(right_sensor==BLACK)){
     Serial.println("going forward! ALL BLACK");
    _mForward();
    delay(2);
   }
   else {
    Serial.println("spinning!");
      _mleft(); 
      delay(2);
  } 
}
