#define button1 25 
#define button2 26

void setup() {
 Serial.begin(9600);
 pinMode(button1,INPUT_PULLUP);
 pinMode(button2,INPUT);
}

void loop() {
  
  int ReadSwitch1 = digitalRead(button1);
  if (ReadSwitch1 == LOW){
    delay(50);
    Serial.println("Button 1 Pressed"); 
  }
  
  int ReadSwitch2 = digitalRead(button2);
  if (ReadSwitch2 == HIGH){
    delay(50);
    Serial.println("Button 2 Pressed"); 
  }
  
}
