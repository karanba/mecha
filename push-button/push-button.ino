const int LED_PIN = 13;
const int PUSH_BUTTON_PIN =8;

bool state = false;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(PUSH_BUTTON_PIN, INPUT); 
  digitalWrite(LED_PIN, LOW);
  digitalWrite(PUSH_BUTTON_PIN, LOW);
}

void loop()
{
  if(digitalRead(PUSH_BUTTON_PIN) == HIGH){
   state = !state; 
    delay(300); 

  }
  
  if(state){
  	digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
  
}