#include <SPI.h>
#include <Ethernet.h>
#include "PubNub.h"
#include "ardui_wrapper.h"

// Some Ethernet shields have a MAC address printed on a sticker on the shield;
// fill in that address here, or choose your own at random:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };


char pubkey[] = "demo";
char subkey[] = "demo";
char channel[] = "button-reply";
char uuid[] = "bana";
int subsuccess = 0;
int pubsuccess = 0;
iotwrapper ard;

void setup()
{
       
	Serial.begin(9600);
	Serial.println("Serial set up");

	while (!Ethernet.begin(mac)) {
		Serial.println("Ethernet setup error");
		delay(1000);
	}
	Serial.println("Ethernet set up");

        
	ard.initvar( pubkey, subkey, uuid); 
	Serial.println("PubNub set up");
       
}

void loop()
{
        
      
	Ethernet.maintain();
        
        //Publish
	Serial.println("publishing a message");
        int pubsuccess = ard.sendArd(channel,"\"Hey There\"");
        

        //Subscribe
	Serial.println("waiting for a message (subscribe)");
        int sucbsuccess = ard.connectArd(channel);
	

	Serial.println();
        

	
}
