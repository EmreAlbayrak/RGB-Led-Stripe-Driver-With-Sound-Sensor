/*-------------------------------------------------------------------------------
| *This program developed for drive the rgb leds with arduino sound sensor.      |
| *When sound sensor value reaches PeakLimit, leds flashes with selected colour. |
| *Copyright by Emre Albayrak                                                    |
 -------------------------------------------------------------------------------*/                         

const int SensorPin = 1;
int Value;                 
int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;

const int PeakLimit =250;

void setup()
{
 pinMode(RedPin, OUTPUT);
 pinMode(GreenPin, OUTPUT);
 pinMode(BluePin, OUTPUT);
}

void loop(){

Value = analogRead(SensorPin);

//SetColour(0, 255, 255); //red            //select a colour
//SetColour(255, 0, 255); //green
//SetColour(255, 255, 0); //blue
//SetColour(0, 0, 255); //yellow
//SetColour(0,220, 255); //orange
//SetColour(0, 255, 80); //purple
//SetColour(255, 80, 0); //sky blue
//SetColour(0, 0, 0); //white

if(Value > PeakLimit){ 
   SetColour(0, 0, 0); //white             //paste this line
 }
else{
   SetColour(255, 255, 255); //turn leds off
 }
}

void SetColour(int red, int green, int blue){
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(RedPin, red);
  analogWrite(GreenPin, green);
  analogWrite(BluePin, blue);
}
