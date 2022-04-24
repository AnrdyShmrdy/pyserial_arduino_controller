const int baud_r = 9600;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(baud_r);
}

void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == '0')
    {
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
      Serial.println("OFF");
      delay(10);
    }    
    else if (ch == '1')
    {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println("ON");
      delay(10);
    }
  }
}
