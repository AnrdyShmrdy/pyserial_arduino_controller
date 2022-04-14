const int wait = 10; //delay in ms after each case in switch statement
const int ascii_a = int('a'); //'a'=97
const int ascii_A = int('A'); //'A'=65
const int ascii_z = int('z'); //'z'=90
const int ascii_Z = int('Z'); //'Z'=122
const int ucase_offset = ascii_A-1; //subtract from uppercase letter ascii value to get pin# for Arduino
const int lcase_offset = ascii_a-1; //subtract from lowercase letter ascii value to get pin# for Arduino
void setup() 
{
  for(int i=1; i <=26; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    int ascii_ch = int(ch);

    if(ascii_ch >= ascii_A && ascii_ch <= ascii_Z){ //from 'A' to 'Z' (is letter uppercase?)
     Serial.println("You entered the following uppercase alphabetical letter: " + ch);
     digitalWrite(ascii_ch-ucase_offset, HIGH); //Set 'HIGH' because uppercase. Subtract ucase_offset to get pin number
     delay(wait);
    }
    else if (ascii_ch >= ascii_a && ascii_ch <= ascii_z){ //from 'a' to 'z' (is letter lowercase?)
     Serial.println("You entered the following lowercase alphabetical letter: " + ch);
     digitalWrite(ascii_ch-lcase_offset, LOW); //Set 'LOW' because lowercase. Subtract lcase_offset to get pin number
     delay(wait);
    }
    else{
      Serial.println("You entered: " + ch);
      delay(wait);
    }
  }
}
