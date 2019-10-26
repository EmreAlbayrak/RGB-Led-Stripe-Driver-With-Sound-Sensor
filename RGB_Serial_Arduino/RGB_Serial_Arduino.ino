/*-------------------------------------------------------------------------------
| *This program developed for drive the rgb leds with arduino sound sensor.      |
| *When sound sensor value reaches PeakLimit, leds flashes with selected colour. |
| *In this version, python serial control option available.                      |
| *Copyright by Emre Albayrak ©                                                  |
 -------------------------------------------------------------------------------*/                         

/*Colours*/
  //SetColour(0, 255, 255); //red           
  //SetColour(255, 0, 255); //green
  //SetColour(255, 255, 0); //blue
  //SetColour(0, 0, 255); //yellow
  //SetColour(0,220, 255); //orange
  //SetColour(0, 255, 80); //purple
  //SetColour(255, 80, 0); //sky blue
  //SetColour(0, 0, 0); //white

const int SensorPin = 1;
int Value;                 
int RedPin = 10;
int GreenPin = 9;
int BluePin = 11;

int PeakInput;
int PeakLimit = 200; //default peak limit
int SerialColour = '8'; //default colour

char SerialData[10];

void setup(){
 pinMode(RedPin, OUTPUT);
 pinMode(GreenPin, OUTPUT);
 pinMode(BluePin, OUTPUT);
 Serial.begin(9600);
}

//--------------------------------------------------Main Loop Here


void loop(){
  Value = analogRead(SensorPin);
  if(Value > PeakLimit){ 
     colour(SerialColour);
    }
    else{
      SetColour(255, 255, 255); //turn leds off
    }

  if(Serial.available()>0){  
    Serial.readBytes(SerialData,4);
    if(SerialData[0] == 'c'){
      SerialColour = SerialData[1]; //SerialData is coming ascii. I need to convert ascii to int.
      Serial.print("\nNew colour : ");
      Serial.print((char)SerialColour);
    }
    if(SerialData[0] == 'p'){
      PeakInput = SerialData[1]; //Also same situation happens here.
      PeakLimit = peak(PeakInput);
    }
  }
}

//--------------------------------------------------Functions Here
int peak(int peakinput){
  if(peakinput == '1'){
    return 80;
  }
  if(peakinput == '2'){
    return 100;
  }
  if(peakinput == '3'){
    return 200;
  }
  if(peakinput == '4'){
    return 300;
  }
  if(peakinput == '5'){
    return 400;
  }
  if(peakinput == '6'){
    return 500;
  }
  if(peakinput == '7'){
    return 600;
  }
  if(peakinput == '8'){
    return 700;
  }
  if(peakinput == '9'){
    return 800;
  }
}

void colour(int NumOfColour){
  if(NumOfColour == '1'){
    return SetColour(0, 255, 255); //red
  }
  if(NumOfColour == '2'){
    return SetColour(255, 0, 255); //green
  }
  if(NumOfColour == '3'){
    return SetColour(255, 255, 0); //blue
  }
  if(NumOfColour == '4'){
    return SetColour(0, 0, 255); //yellow
  }
  if(NumOfColour == '5'){
    return SetColour(0,220, 255); //orange
  }
  if(NumOfColour == '6'){
    return SetColour(0, 255, 80); //purple
  }
  if(NumOfColour == '7'){
    return SetColour(255, 80, 0); //sky blue
  }  
  if(NumOfColour == '8'){
    return SetColour(0, 0, 0); //white
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
