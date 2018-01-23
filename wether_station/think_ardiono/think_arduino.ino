/*********************************************
 this code sends data frtom esp 8266 01 to think speak 
 
******************************************************/ 
#include <DHT.h>
#include <ESP8266WiFi.h>
 
// replace with your channel's thingspeak API key, 
String apiKey = "QKDDFETSYQW6XVXW";//Api key of think speak.com
const char* ssid = "Mahadev";//my wifi ssid
const char* password = "12345678";//my wifi password
 
const char* server = "api.thingspeak.com";//server name
#define DHTPIN 2 // what pin we're connected to
 
DHT dht(DHTPIN, DHT22,15);
WiFiClient client;
   
 
void setup() {                
  Serial.begin(115200);//serial set for esp 8266 01
  delay(10);// for setting up the sensor
  dht.begin();// sernsor begins
  
  WiFi.begin(ssid, password);//enter parameretes in wifi
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);// prtint ssid id name on serial 
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);// to setup the wifi chip
    Serial.print(".");// untill wifi connected it will gonna print  dots on serial
  }
  Serial.println("");
  Serial.println("WiFi connected");// is wifi is connected
  
}
 
 
void loop() {
   
  float h = dht.readHumidity();// floating point value of humidity 
  float t = dht.readTemperature();// floating point value of temperature
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");// in case unable to initialize sensor
    return;
  }
 
  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiKey;
           postStr +="&field1=";//shows humidity on think speak
           postStr += String(t);
           postStr +="&field2=";//shows temperature on think speak
           postStr += String(h);
           postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n"); 
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(postStr.length()); 
     client.print("\n\n"); 
     client.print(postStr);
           
 
     Serial.print("Temperature: ");
     Serial.print(t);
     Serial.print(" degrees Celcius Humidity: "); 
     Serial.print(h);
     Serial.println("% send to Thingspeak");    
  }
  client.stop();
   
  Serial.println("Waiting...");    
  // thingspeak needs minimum 15 sec delay between updates
  delay(3600000);  // sends data on every 20seconds
}

