/*
 * This code made by white collar crew to check the current consution by ESp 8266 01 with diffrent modes by using reset button
 * ESP8266 01 in Deep sleep mode 
 */
 
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);
  // Wait for serial to initialize.
  while(!Serial) { }  
  // Deep sleep mode until RESET pin is connected to a LOW signal (for example pushbutton or magnetic reed switch)
  Serial.println("I'm awake, but I'm going into deep sleep mode until RESET pin is connected to a LOW signal");
  Serial.println("Check the current consumption please");
  ESP.deepSleep(0);//wake up on intrupt
   
  
}

void loop() {
}
