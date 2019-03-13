/*---------------------------------------------------------------------------------------
| *This program developed for drive the rgb leds with arduino sound sensor.              |
| *When sound sensor reaches PeakLimit, leds flashes and select random colour every peak.|
| *Copyright by Emre Albayrak                                                            |
 ---------------------------------------------------------------------------------------*/

const int SensorPin = 1;
int Value;   
              
int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;
int RandomVar;

const int PeakLimit =250;

void setup(){
 pinMode(RedPin, OUTPUT);
 pinMode(GreenPin, OUTPUT);
 pinMode(BluePin, OUTPUT);
 RandomVar=1;
}

void loop(){

Value = analogRead(SensorPin);

if(Value > PeakLimit){ 

  if (RandomVar==1){
   SetColour(0, 255, 255); //red
  }
  if (RandomVar==2){
   SetColour(255, 0, 255); //green
  }
  if (RandomVar==3){
   SetColour(255, 255, 0); //blue
  }
  if (RandomVar==4){
   SetColour(0, 0, 255); //yellow
  }
  if (RandomVar==5){
   SetColour(0,220, 255); //orange
  }
  if (RandomVar==6){
   SetColour(0, 255, 80); //purple 
  }
  if (RandomVar==7){
   SetColour(255, 80, 0); //sky blue  
  }
  if (RandomVar==8){
   SetColour(0, 0, 0); //white  
  }
 }
 else{
  SetColour(255, 255, 255);
  RandomVar = random(1, 8);
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
