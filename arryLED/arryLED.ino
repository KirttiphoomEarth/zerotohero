int led[8] = {13,12,14,27,14,12};
void setup() {
  for(int i=0;i<4;i++){
    pinMode(led[i],OUTPUT);
  }
}
void loop() {
  for(int i=0 ; i < 6 ; i++){
    digitalWrite(led[i],1);
    delay(100);
    digitalWrite(led[i],0);
    delay(100);
  }
}
 
