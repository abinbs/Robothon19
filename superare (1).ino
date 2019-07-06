String command;
const int M1F = 3, M1B = 2,       //B - Backward
          M2F = 5, M2B = 4,       //F - Forward 
          M3F = 6, M3B = 7,
          M4F = 9, M4B = 8;

void turnRight();
void turnLeft();
void goForward();
void goBack();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    delay(10);
    char ch=Serial.read();
    if(ch=='#')
      break;
    command+=ch;
  }
  if(command.length()>0)
  {
    Serial.println(command);
    if(command=="*right")
      turnright();

    if(command=="*left")
      turnleft();

    if(command=="*forward")
      goforward();

    if(command=="*back")
      goback();
  }

}

void turnright()
{
  analogWrite(M1F,255);
  analogWrite(M3F,255);
  analogWrite(M2B,255);
  analogWrite(M4B,255);
  delay(1000);
}

void turnleft()
{
  analogWrite(M1B,255);
  analogWrite(M3B,255);
  analogWrite(M2F,255);
  analogWrite(M4F,255);
  delay(1000);
}

void goforward()
{
  analogWrite(M1F,255);
  analogWrite(M2F,255);
  delay(1000);
}

void goback()
{
  analogWrite(M1B,255);
  analogWrite(M2B,255);
  delay(1000);
}
