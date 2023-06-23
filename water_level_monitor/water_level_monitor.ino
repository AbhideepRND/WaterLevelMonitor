int pushButton = 8;
int LED = 13;

void setup() {
  Serial.begin(115200);
  pinMode(pushButton, INPUT_PULLUP);
}

void loop() {
  int val = analogRead(A0);  // read the input pin
  Serial.println(val); 
  int val1 = digitalRead(pushButton);
  Serial.println(val1);   
}