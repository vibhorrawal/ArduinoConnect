//motors
#define lmotor 9
#define rmotor 3
#define lbmotor 6
#define rbmotor 5

//speeds
#define HSPEED 255
#define SPEED 200
char data;
void setup() {

  Serial.begin(9600);
  pinMode(lmotor, OUTPUT);
  pinMode(rmotor, OUTPUT);
  pinMode(lbmotor, OUTPUT);
  pinMode(rbmotor, OUTPUT);

  analogWrite(lmotor, 0);
  analogWrite(rmotor, 0);
  analogWrite(lbmotor, 0);
  analogWrite(rbmotor, 0);

}

void loop() {
  int i = 0;
  if (Serial.available())
  {

    data = Serial.read();
    Serial.write(data);

    switch (data)
    {
      case '1':
        i = 1;
        analogWrite(lmotor, HSPEED);
        analogWrite(rmotor, HSPEED);
        Serial.println("Forward");
        break;

      case '2':
        analogWrite(lbmotor, HSPEED);
        analogWrite(rbmotor, HSPEED);
        Serial.println("Backward");
        break;

      case '3':
        if(i==0)
        analogWrite(rmotor, HSPEED);
        else
        analogWrite(rmotor, SPEED);
        Serial.println("Left");
        break;

      case '4':
        if(i==0)
        analogWrite(lmotor, HSPEED);
        else
        analogWrite(lmotor, SPEED);
        Serial.println("Right");
        break;

      case '5':
        analogWrite(lmotor, 0);
        analogWrite(rmotor, 0);
        analogWrite(lbmotor, 0);
        analogWrite(rbmotor, 0);
        Serial.println("Stop");
        i = 0;
        break;

      case '6': //with 3
        if (i == 0)
          analogWrite(rmotor, 0);
        else
          
          {
            analogWrite(rmotor, HSPEED);
            analogWrite(lmotor, SPEED);
            
          }
        i = 0;
        break;

      case '7':
        if (i == 0)
          analogWrite(lmotor, 0);
        else
         {
          analogWrite(lmotor, HSPEED);
          analogWrite(rmotor, SPEED);
         }
        i = 0;
        break;


    }
    delay(100);
  }
}



