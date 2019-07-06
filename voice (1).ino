String command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    delay(10);
    char ch = Serial.read();
    if(ch=='#')
      break;
    command+=ch;
    Serial.println(command);
  }
  if(command.length()>0)
  {
    Serial.println(command);
    if(command=="open")
    {
      Serial.println("ledon");
      digitalWrite(13,HIGH);
      delay(1000);
    }
    if(command=="close")
    {
      Serial.println("ledoff");
      digitalWrite(13,LOW);
      delay(1000);
    }
    delay(1000);
    command="";
  }
}
