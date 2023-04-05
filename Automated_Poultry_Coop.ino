#include <Servo.h>
Servo tap_servo;
int rain_pin = 12;//RAIN PIN
int tap_servo_pin =9; //SERVO PIN
int val;//RAINVALUE
int value =0;//IR VALUE

void setup() {
  

  //IR and BUZZER part
  pinMode(4,INPUT);
  pinMode(11,OUTPUT);//buzzer
  Serial.begin(9600);

  //temperature part
  pinMode(A3, INPUT); //sensor
  pinMode(2, OUTPUT); //yellow  checks if temp is cold
  // pinMode(3, OUTPUT); //green  temp is normal
  // pinMode(5, OUTPUT); //red checks if the temp is hot
  //sERVO
  pinMode(rain_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
  Serial.begin(9600);
}

void loop() {

  //code for IR AND BUZZER SENSOR
  // put your main code here, to run repeatedly:
  value = digitalRead(4);
  Serial.println(value);
  if(digitalRead(4)==LOW){  
    digitalWrite(11,HIGH);
    tone(11,200);
    delay(100);
    noTone(11);
}
else{
  digitalWrite(11,LOW);
}
  
  

  delay(500);

  //termp part
  const int hot = 800 ; //set hot parameter
  const int cold = 700; //set cold parameter  90 start

  int sensor = analogRead(A3);
  float voltage = (sensor / 1024.0) * 5.0;
  float tempC = (voltage - .5) * 80;  //100 to 80
  float tempF = (tempC * 1.8) + 32;
  Serial.print("temp: ");
  Serial.print(tempF);
  if (tempF < cold) { //cold
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  Serial.println(" It's Cold.");
}
else if (tempF >= hot) { //hot
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  Serial.println(" It's Hot.");
}
else { //fine
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(5, LOW);
  Serial.println(" It's Fine.");
}
delay(10);
val = digitalRead(rain_pin);

  if (val==0)
  {
    tap_servo.write(180);
    delay(200);
  
  }
  if (val==1)
  { 
    tap_servo.write(0);
    delay(200);
    }
}
