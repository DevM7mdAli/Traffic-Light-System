// pins numbers
const int red = 2;
const int yellow = 3; 
const int green = 4; 
const int btn = 5 ; 

int fastMode(){
  if(digitalRead(btn) == 1){
    Serial.print("fast Mode is On\n");
    return 300;
  } else {
    return 1000;
  }
}

int flashingLightMode(){
    if(digitalRead(btn) == 1){
    Serial.print("Flash fast Mode is On\n");
    return 300;
  } else {
    return 600;
  }
}

void redLight(int time){
  digitalWrite(red, HIGH);
  Serial.print ("Red light stop\n");
  for (int i = time; i > 0 ; i--){
      Serial.print ("Will be green after ");
      Serial.print (i);
      Serial.print (" seconds");
      Serial.print ("\n");
      delay(fastMode());
  }
  digitalWrite(red, LOW); // red light off
}


void greenLight(int time){
  digitalWrite(green, HIGH);
  Serial.print("Green light go\n");
  for (int i = time; i > 0 ; i--){
      // for the soon cloosing
      if(i <= 5){
          Serial.print ("Will be yellow after ");
          Serial.print (i);
          Serial.print (" seconds Hurry!");
          Serial.print ("\n");
          digitalWrite(green, LOW);
          delay(flashingLightMode());
          digitalWrite(green, HIGH);
          delay(flashingLightMode());
          continue;
      }
      Serial.print ("Will be yellow after ");
      Serial.print (i);
      Serial.print (" seconds");
      Serial.print ("\n");
      delay(fastMode());
  }
  digitalWrite(green, LOW); // green light off
}

void yellowLight(int time){
  digitalWrite(yellow, HIGH);
  Serial.print ("Green light go\n");
  for (int i = time; i > 0 ; i--){
          Serial.print ("Will be red after ");
          Serial.print (i);
          Serial.print (" seconds Hurry!");
          Serial.print ("\n");
          digitalWrite(yellow, LOW);
          delay(flashingLightMode());
          digitalWrite(yellow, HIGH);
          delay(flashingLightMode());
          continue;
      }
  digitalWrite(yellow, LOW);
}

void setup() {
  pinMode(red, OUTPUT); 
  pinMode(yellow, OUTPUT); 
  pinMode(green, OUTPUT); 
  pinMode(btn , INPUT);
    Serial.begin(9600);
    Serial.print ("start the code\n");
}


void loop() {
  Serial.begin(9600);  // for printing
  //prameters for time ON
    redLight(5);
    greenLight(10);
    yellowLight(3);
}
