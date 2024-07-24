
void setup() {
  pinMode(2, OUTPUT); // red light stop
  pinMode(3, OUTPUT); // yellow light slow down
  pinMode(4, OUTPUT); // green light go
    Serial.begin(9600);
    Serial.print ("start the code\n");
}

// the loop function runs over and over again forever
void loop() {
  Serial.begin(9600);  // for printing
  digitalWrite(2, HIGH);
  Serial.print ("Red light stop\n");
  for (int i = 5; i > 0 ; i--){
      Serial.print ("Will be green after ");
      Serial.print (i);
      Serial.print (" seconds");
      Serial.print ("\n");
      delay(1000);
  }
  digitalWrite(2, LOW); // red light off


  digitalWrite(4, HIGH);
  Serial.print ("Green light go\n");
  for (int i = 15; i > 0 ; i--){
      // for the soon cloosing
      if(i <= 5){
          Serial.print ("Will be yellow after ");
          Serial.print (i);
          Serial.print (" seconds Hurry!");
          Serial.print ("\n");
          digitalWrite(4, LOW);
          delay(600);
          digitalWrite(4, HIGH);
          delay(600);
          continue;
      }
      Serial.print ("Will be yellow after ");
      Serial.print (i);
      Serial.print (" seconds");
      Serial.print ("\n");
      delay(1050);
  }
digitalWrite(4, LOW); // green light off


  digitalWrite(3, HIGH);
  Serial.print ("Green light go\n");
  for (int i = 4; i > 0 ; i--){
          Serial.print ("Will be red after ");
          Serial.print (i);
          Serial.print (" seconds Hurry!");
          Serial.print ("\n");
          digitalWrite(3, LOW);
          delay(600);
          digitalWrite(3, HIGH);
          delay(600);
          continue;
      }
digitalWrite(3, LOW);
}
