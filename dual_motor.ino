#define in A0
#define out1 3
#define out2 5
#define sw 4

bool state = false;
bool lastState = LOW;

void setup()
{
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop(){
  bool currentState = digitalRead(sw);
  int analogValue = analogRead(in);
  int m1 = map(analogRead(in), 0, 1023, 255, 0);
  int m2 = map(analogRead(in), 0, 1023, 0, 255);
  
  if (lastState == LOW && currentState == HIGH){
  	state = !state;
    delay(50);
  }
  
  lastState = currentState;
  
  if (state){
    analogWrite(out1, 0);
  	analogWrite(out2, 0);  	
  } else {
    analogWrite(out1, m1);
  	analogWrite(out2, m2);
  }
}