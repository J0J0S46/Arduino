
#define sw 10
#define screenWidth 600
#define screenHeight 600
int buzzer = 13;//intialize buzzer to pin 13
int fan = 2;//initialize fan to pin 2

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(sw,INPUT_PULLUP);// setting pin sw as input
  pinMode(13,OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fan, OUTPUT);

}
 
void loop() {
  int x = analogRead(A4);// read analog from A4
  int y = analogRead(A5);// read analog from A5
  int xPos = map(x, 0, 1023,0,screenWidth);//use map function to limit the output according to "screenWidth" variable
  int yPos = map(y, 0, 1023,0,screenHeight);//use map function to limit the output according to "screenHeight" variable 
  int sStat = digitalRead(sw);//check if joystick is pressed down
  // Robojax project
  
  //print output
  Serial.print("X: ");
  Serial.print(xPos);// Robojax prints x

  Serial.print(" Y: ");
  Serial.println(yPos);// Robojax prints y
  
  //if joystick's button is pressed then the LED is ON else is OFF
  if(sStat ==LOW){
    Serial.println("Switch pressed");
    digitalWrite(13,HIGH);// Turn LED ON
  }else{
    digitalWrite(13,LOW);// Turn LED OFF
  }
  
  //to trigger fan & buzzer
  if (x>= 100 && y==100) {
    digitalWrite(fan, HIGH);
    tone(buzzer , HIGH);
    delay(5000);
  } else {
    digitalWrite(fan, LOW);
    noTone(buzzer);
    
  }
  //time to loop the program & print the output(0.5 sec)
  delay(50);
}
