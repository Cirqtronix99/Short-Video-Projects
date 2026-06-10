//.................Automatic Night Light by CIRQTRONIX.................

#define led 9
#define ldr A0

int threshold = 600; //keep this between 400 and 1000

void setup()
{
  pinMode(led,OUTPUT);
}

void loop()
{
  int val = analogRead(ldr);
  if(val > threshold)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  delay(200);
}
