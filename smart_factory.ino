//Integrated Control CODE
//Control Fan Motor
//Control Water Level
//This sketch turns the Fan Motor ON and OFF based on measured temperature and set UCL and LCL
//It also prints the analog read value from the thermistor
//This sketch monitors and controls the water level in the Chemical Bath and Reservoir

int tempval = 0;  // variable to store temperature value read at analog pin 2
int waterval = 100; // variable to store analog water level value
float temp = 0;   //leftover from previous Test sketch

//Setup of setpoint, UCL, and LCL
int setpoint = 511;
//int setpoint = analogRead(5);
int UCL = setpoint + 4;
int LCL = setpoint - 4;

void setup() {
  pinMode(8, OUTPUT); //digital pin 8 controls Fan Motor
  pinMode(3, OUTPUT); //digital pin 7 controls LED Heater
  pinMode(6, OUTPUT); //digital pin 6 controls Mini-Pump
  Serial.begin(9600); //set up to print out text to monitor
}

void loop() {
  delay(4000);
  //  Serial.print("Setpoint = ");
  //  Serial.print(setpoint);
  Serial.print("UCL = "); Serial.print(UCL);
  Serial.print("  LCL = "); Serial.println(LCL);
  tempval = analogRead(4);  // read thermister analog input pin 5
  Serial.print("Current Temp = ");
  Serial.println(tempval);    // print thermister value to serial monitor

  //IF-THEN-ELSE for Temperature
  if (tempval <507)//change
  {
    Serial.println("***tempval < LCL -- Turn ON LED");
    LEDON();
  }
  else if (tempval > 515)//change
  {
    Serial.println("***tempval > UCL -- Turn OFF LED, Turn ON Fan");
    LEDOFF();
  }
  else {}

  //IF-THEN-ELSE for Water Level
  waterval = analogRead(2);  // read water sensor analog input pin 4
  Serial.print("H2O level = "); Serial.println(waterval);
  Serial.println("LCL of H20 = 690");
  if (waterval <690)
  {
    PUMPON();
  }
  else {}
  Serial.println();
}

void LEDON() {
  //  Serial.println("In LCL Function");
  digitalWrite(3, HIGH); //LED ON
}

void LEDOFF() {
  //  Serial.println("In UCL Function");
  digitalWrite(3, LOW);  //LED OFF
  digitalWrite(8, HIGH); //Fan ON
  delay(10000);
  digitalWrite(8, LOW);  //Fan OFF
}

void PUMPON() {
  Serial.println("In PUMP Function");
  digitalWrite(6, HIGH);  //Mini-pump ON
  delay(7000);  //time to operate mini-pump
  digitalWrite(6, LOW);   //Turn OFF mini-pump
}

//digitalWrite(8, HIGH); //Fan ON
//delay(2000);
//digitalWrite(8, LOW);  //Fan OFF
//delay(2000);

//digitalWrite(3, HIGH); //LED ON
//delay(2000);
//digitalWrite(3, LOW);  //LED OFF
//delay(2000);
