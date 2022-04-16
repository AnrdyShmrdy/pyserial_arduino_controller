const int baud_r = 9600;
const int fPinNo = 2; //first pin number = 'a' or 'A'
const int lPinNo = 13; //last pin number = 'z' or 'Z'
const int ucase_offset = int('A')-fPinNo; //subtract from uppercase letter ascii value to get pin# for Arduino
const int lcase_offset = int('a')-fPinNo; //subtract from lowercase letter ascii value to get pin# for Arduino
void setup() 
{
  for(int i=fPinNo; i <=lPinNo; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(baud_r);
}

void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if(isUpperCase(ch)){ //is letter uppercase?
     Serial.println(ch);
     int pinToWrite = int(ch)-ucase_offset;
     if(pinToWrite >= fPinNo && pinToWrite <= lPinNo){ //check if we can use the pinNo
        digitalWrite(pinToWrite, HIGH); //Set 'HIGH' because uppercase. Subtract ucase_offset to get pin number
     }
    }
    else if (isLowerCase(ch)){ //is letter lowercase?
     Serial.println(ch);
     int pinToWrite = int(ch)-lcase_offset;
     if(pinToWrite >= fPinNo && pinToWrite <= lPinNo){ //check if we can use the pinNo
        digitalWrite(pinToWrite, LOW); //Set 'LOW' because lowercase. Subtract lcase_offset to get pin number
     }
    }
  }
}
