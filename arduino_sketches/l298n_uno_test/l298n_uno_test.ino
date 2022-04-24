const int baud_r = 9600;
const int fPinNo = 2; //first pin number = 'a' or 'A'
const int lPinNo = 13; //last pin number = 'z' or 'Z'
const int ENA = 9;
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENB = 3;
const int pwm_val = 100;
int DCMotor1[] = {IN1,IN2, ENA};
int DCMotor2[] = {IN3,IN4, ENB}; 
void setup() 
{
  for(int i=fPinNo; i <=lPinNo; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(baud_r);
}

void Start(int motor[], bool pin1, bool pin2, int pwm_val)
{
  pin1 ? digitalWrite(motor[0], HIGH) : digitalWrite(motor[0], LOW);
  pin2 ? digitalWrite(motor[1], HIGH) : digitalWrite(motor[1], LOW);
  analogWrite(motor[2], pwm_val);
}
void Stop(int motor[])
{
  digitalWrite(motor[0], 0);
  digitalWrite(motor[1], 0);
  analogWrite(motor[2], 0);
}

void moveForward(){
  Start(DCMotor1, 1, 0, pwm_val);
  Start(DCMotor2, 1, 0, pwm_val);
}
void moveBackward(){
  Start(DCMotor1, 0, 1, pwm_val);
  Start(DCMotor2, 0, 1, pwm_val);
}
void turnLeft(){
  Start(DCMotor1, 1, 0, pwm_val);
  Start(DCMotor2, 0, 1, pwm_val);
}
void turnRight(){
  Start(DCMotor1, 0, 1, pwm_val);
  Start(DCMotor2, 1, 0, pwm_val);
}
void stopMoving(){
  Stop(DCMotor1);
  Stop(DCMotor2);
}
void testMotors(){
  moveForward();
  delay(2000);
  stopMoving();
  delay(2000);
  moveBackward();
  delay(2000);
  stopMoving();
  delay(2000);
}
void loop() 
{
 testMotors(); 
}
