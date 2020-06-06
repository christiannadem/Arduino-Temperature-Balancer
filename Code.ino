const float hot = 26.0; //Setting Hot Parameter

const float cold = 17.0; //Setting Cold Parameter

//The Setup Function (Runs once on Power and Reset)
void setup(){
  pinMode(A2, INPUT); //Temperature Sensor
  pinMode(2, OUTPUT); //Red Led
  pinMode(3, OUTPUT); //Green Led
  pinMode(4, OUTPUT); //Blue Led
  Serial.begin(9600); //Prepares Serial Monitor
}

//The Loop Function runs forever
void loop(){
  int sensor = analogRead(A2); //Reads Analog Value from pin A2
  float voltage = 5.0 * (sensor / 1024.0); //Calculate Sensor's Voltage
  float tempCelsius = (voltage - 0.5) * 100; //Calculate Celsius Temperature
  float tempFahrenheit  = (tempCelsius * 1.8) + 32; //Convert to Fahrenheit Temperature
  
    //Prints the Temperature Value to the Serial Monitor into Celsius and Fahrenheit
  Serial.print("The Temperature is: ");
  Serial.print(tempCelsius);
  Serial.print(" C or ");
    Serial.print(tempFahrenheit);
    Serial.print(" F.");
  
    //Checks Temperature Value and Light Up Leds
  if(tempCelsius < cold){ //If Temperature is smaller than cold
    digitalWrite(4, HIGH); //Turn the Blue Led On
    digitalWrite(3, LOW); //Turn the Green Led Off
    digitalWrite(2, LOW); //Turn the Red Led Off
    Serial.println(" It is Cold."); //Prints Status of Room
  }
  else if(tempCelsius >= hot){ //If Temperature is bigger than hot
    digitalWrite(4, LOW); //Turn the Blue Led Off
    digitalWrite(3, LOW); //Turn the Green Led Off
    digitalWrite(2, HIGH); //Turn the Red Led On
    Serial.println(" It is Hot."); //Prints Status of Room
  }
  else{ //If Temperature is fine
    digitalWrite(4, LOW); //Turn the Blue Led Off
    digitalWrite(3, HIGH); //Turn the Green Led On
    digitalWrite(2, LOW); //Turn the Red Led Off
    Serial.println(" It's Fine."); //Prints Status of Room
  }
  
  Serial.println(" ");
    delay(1000); //Waits for a second
}
