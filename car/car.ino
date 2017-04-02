//Accelerometer pin config
int VccPin = A1; //Set Analog pin A1 as VCC
int xPin = A2; //X axis input
int yPin = A3; //Y axis input
int zPin = A4; //Z axis input (Not required)
int GNDPin = A5; //Set Analog pin A5 as GND

//Accelerometer output pins config
long x; //Variabe for storing X coordinates
long y; //Variabe for storing Y coordinates
long z; //Variabe for storing Z coordinates

//Encoder pin config
int O1=10,O2=11,O3=12,O4=13; //Output pins to be connected to 10, 11, 12, 13 of Encoder IC

byte debug = 0;   //set to 1 to debug


void setup() {
  if(debug)
    Serial.begin(9600);     //To debug
  pinMode(O1,OUTPUT);
  pinMode(O2,OUTPUT);
  pinMode(O3,OUTPUT);
  pinMode(O4,OUTPUT);
  pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);

  //Switch on accelerometer
  digitalWrite(GNDPin, LOW);        //Set A5 pin to LOW for GND
  digitalWrite(VccPin, HIGH);       //Set A5 pin to HIGH for Vcc
}

void loop() {
  //analogReference(EXTERNAL);
  x = analogRead(xPin);     //Reads X coordinates
  y = analogRead(yPin);     //Reads Y coordinates
  z = analogRead(zPin);     //Reads Z coordinates (Not Required)

  /*int a, b, c, d;         //To debug
  a = digitalRead(3);       //Connect decoder output to Arduino to check {Encoder -- RF TX/RX -- Decoder}
  b = digitalRead(4);
  c = digitalRead(5);
  d = digitalRead(6);*/
  Serial.println(x);
  Serial.println(y);
  

  if(x<340)      // Change the value for adjusting sensitivity  
    left();
  else if(x>400) // Change the value for adjusting sensitivity
    right();
  else if(y>400) // Change the value for adjusting sensitivity
    forward();
  else if(y<340) // Change the value for adjusting sensitivity
    backward();
  else
    stopcar();

  /*Serial.print("Check : ");           //To debug : to check {Encoder -- RF TX/RX -- Decoder}
  Serial.print(a); Serial.print(" ");
  Serial.print(b); Serial.print(" ");
  Serial.print(c); Serial.print(" ");
  Serial.print(d); Serial.print("\n");*/
}

void stopcar() {
  if(debug) {
    Serial.println("");
    Serial.println("STOP");
  }
  
  digitalWrite(O1,LOW);     //Send 0000 to motor terminals
  digitalWrite(O2,LOW);     //All motors stop
  digitalWrite(O3,LOW);
  digitalWrite(O4,LOW);
}

void forward() {
  if(debug) {
    Serial.println("");
    Serial.println("Forward");
  }
  
  digitalWrite(O1,HIGH);    //Send 1010 to motor terminals
  digitalWrite(O2,LOW);     //Turn both motors in opposite directions
  digitalWrite(O3,HIGH);    //Car moves forward
  digitalWrite(O4,LOW);
}

void backward() {
  if(debug) {
    Serial.println("");
    Serial.println("Backward");
  }
  
  digitalWrite(O1,LOW);     //Send 0101 to motor terminals
  digitalWrite(O2,HIGH);    //Turn both motors in opposite directions
  digitalWrite(O3,LOW);     //Opposite of forward; car moves backward
  digitalWrite(O4,HIGH);
}

void right() {
  if(debug) {
    Serial.println("");
    Serial.println("Left");
}
  
  digitalWrite(O1,LOW);     //Send 0110 to motor terminals
  digitalWrite(O2,HIGH);    //Turn both motors in same direction
  digitalWrite(O3,HIGH);    //Car turns right (in our circuit)
  digitalWrite(O4,LOW);
}

void left()
{
  if(debug) {
    Serial.println("");
    Serial.println("Right");
  }
  
  digitalWrite(O1,HIGH);      //Send 1001 to motor terminals
  digitalWrite(O2,LOW);       //Turn both motors in same direction
  digitalWrite(O3,LOW);       //But opposite of right
  digitalWrite(O4,HIGH);      //Car turns left
}
