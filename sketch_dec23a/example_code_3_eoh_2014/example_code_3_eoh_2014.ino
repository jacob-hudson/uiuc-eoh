#include <Servo.h>

Servo serXaxis;  // X acis
Servo serYaxis;  // Y acis
Servo serHaxis;  //riser

int directionFin; //command charcter - where to go?

int Yval;
int Xval;


void setup ()
{
  //setting serbvo Pins
  serHaxis.attach(11);
  serXaxis.attach(10);
  serYaxis.attach(9);

  //start the Serial line.
  Serial.begin(9600);



  //set initial positions - this centers it, check for new motors!
  Xval = 90;
  Yval = 85;
  serHaxis.write(37); //raise camera to standard height.
  serXaxis.write(Xval);  //center the X axis
  serYaxis.write(Yval); //center the Y axis

}

void loop()
{
  Serial.println("0-180 = X Axis, 181-360 = Y axis");
  while (Serial.available() == 0); //checks to amke sure device is connected
  {
     directionFin = Serial.parseInt();
  }
  Serial.println(directionFin);
  
  if (directionFin >= 0 && directionFin <= 179) //left or right
  {
     Serial.println("X"); //remove this in final code - this is for testing
     serXaxis.write(directionFin); //moves to desired position
  }
  else if (directionFin >= 180 && directionFin <= 360) //up and down
  {
    serXaxis.write(directionFin / 2); //converts it to the correct range
  }
  else  //mayve you should pay more attention 
  {
    Serial.println("LNVALID CHARACHTER");
  }

}


