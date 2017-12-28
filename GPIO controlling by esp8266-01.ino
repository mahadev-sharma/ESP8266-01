/****************************************************
Code Created:Mahadev Sharma(7519341)
             Madhav  Chadha(7751993)
             Rishabh Verma (7692007)
Place:Conestoga College 
Client:Robert Edler
Mentor:Ilya Peskov
Group:007
Group name:White Collar Crew
This code allows to create wifi server using ESP8266 -01
ESP8266-01 takes credential from wifi and create own wifi
Creates webpage to control GPIO of ESP8266-01 
*****************************************************/
/******************Wifi creation section***************/
#include <ESP8266WiFi.h>
 
const char* ssid = "Mahadev";//type your ssid
const char* password = "12345678";//type your password
 
int ledPin = 2; // GPIO2 of ESP8266
WiFiServer server(80);//internal server
 
void setup() {
  Serial.begin(115200);//baud rate for wifi
  delay(10);//to set wifi
 
 
  pinMode(ledPin, OUTPUT);//out put made for GPIO
  digitalWrite(ledPin, LOW);//Initiate with low GPIO
   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");//Print on serial terminal 
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);//to connect wifi
    Serial.print(".");//prints untill connects to wifi
  }
  Serial.println("");
  Serial.println("WiFi connected");//shows when wifi connected
   /***********************************************************/
  /***************Server section******************************/  
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  /***********************************************************/  
    
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
/*********Controlling GPIO*************************/ 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
   
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");




  client.println("<meta charset=\"utf-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
  client.println("<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css\" integrity=\"sha384-PsH8R72JQ3SOdhVi3uxftmaW6Vc51MKb0q5P2rRUpPvrszuE4W1povHYgTpBfshb\" crossorigin=\"anonymous\">");
   


  client.println("<h1 style=\"background-color:DodgerBlue;\">Welcome to future</h1>");


  
   
  client.print("Led is ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\">Red</a><br>");
  client.println("<a href=\"/LED=OFF\">Black</a><br>");
  

  client.println("<script src=\"https://code.jquery.com/jquery-3.2.1.slim.min.js\" integrity=\"sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN\" crossorigin=\"anonymous\"></script>");
  client.println("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.3/umd/popper.min.js\" integrity=\"sha384-vFJXuSJphROIrBnz7yo7oB41mKfc8JzQZiCq4NCceLEaO4IHwicKwpJf9c9IpFgh\" crossorigin=\"anonymous\"></script>");
  client.println("<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/js/bootstrap.min.js\" integrity=\"sha384-alpBpkh1PFOepccYVYDB4do5UnbKysX5WZXm3XxPqe5iKTfUKjNkCk9SaVuEZflJ\" crossorigin=\"anonymous\"></script>  "); 
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
