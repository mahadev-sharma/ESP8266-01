//MAhadev Sharma
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>

unsigned int request_i = 0;
unsigned int response_i = 0;

String manageRequest(String request);


ESP8266WiFiMesh mesh_node = ESP8266WiFiMesh(ESP.getChipId(), manageRequest);

//call back
String manageRequest(String request)
{
	/* Print out received message */
	Serial.print("received: ");
	Serial.println(request);

	// return a string to 
	char response[60];
	sprintf(response, "Hello world response #%d from Mesh_Node%d.", response_i++, ESP.getChipId());
	return response;
}

void setup()
{
	Serial.begin(115200);
	delay(10);

	Serial.println();
	Serial.println();
	Serial.println("Setting up mesh node...");

	// Initialise 
	mesh_node.begin();
}

void loop()
{
	// incoming connections 
	mesh_node.acceptRequest();

	/* Scan for other nodes and send them a message */
	char request[60];
	sprintf(request, "Hello world request #%d from Mesh_Node%d.", request_i++, ESP.getChipId());
	mesh_node.attemptScan(request);
	delay(1000);
}
