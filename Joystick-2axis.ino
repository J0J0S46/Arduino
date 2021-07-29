
#define sw 10
#define screenWidth 600
#define screenHeight 600
int buzzer = 13;
int fan = 2;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(sw,INPUT_PULLUP);// setting pin sw as input
  pinMode(13,OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fan, OUTPUT);

}
 
void loop() {
  // Robojax Dual Axis joystick project
  int x = analogRead(A4);// read analog
  int y = analogRead(A5);
  int xPos = map(x, 0, 1023,0,screenWidth);
  int yPos = map(y, 0, 1023,0,screenHeight); 
  int sStat = digitalRead(sw);//
  // Robojax project

  Serial.print("X: ");
  Serial.print(xPos);

  Serial.print(" Y: ");
  Serial.println(yPos);// Robojax prints y
  if(sStat ==LOW){
    Serial.println("Switch pressed");
    digitalWrite(13,HIGH);// Turn LED ON
  }else{
    digitalWrite(13,LOW);// Turn LED OFF
  }
  if (x>= 100 && y==100) {
    digitalWrite(fan, HIGH);
    tone(buzzer , HIGH);
    delay(5000);
  } else {
    digitalWrite(fan, LOW);
    noTone(buzzer);
    
  }
  delay(50);
}
