#define FD 16
#define BD 17
#define LD 18
#define RD 19
#define m11 3
#define m12 4
#define m21 5
#define m22 6
void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}
void left()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}
void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}
void setup() 
{
  pinMode(FD, INPUT);
  pinMode(BD, INPUT);
  pinMode(LD, INPUT);
  pinMode(RD, INPUT);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  int temp1=digitalRead(FD);
  int temp2=digitalRead(BD);
  int temp3=digitalRead(LD);
  int temp4=digitalRead(RD);

  Serial.print(temp1); Serial.print(" "); Serial.print(temp2); Serial.print(" "); Serial.print(temp3); Serial.print(" "); Serial.print(temp4); Serial.print(" "); Serial.print("\n"); 
  
  if(temp1==1 && temp2==0 && temp3==0 && temp4==0) {
  backward();
  }
  else if(temp1==0 && temp2==1 && temp3==0 && temp4==0)
  forward();
  else if(temp1==0 && temp2==0 && temp3==1 && temp4==0)
  left();
  else if(temp1==0 && temp2==0 && temp3==0 && temp4==1)
  right();
  else
  Stop();
}
