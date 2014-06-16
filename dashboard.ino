#include <SPI.h>
#include <Ethernet.h>
#include "string.h"
#include "ardui_wrapper.h"

// Some Ethernet shields have a MAC address printed on a sticker on the shield;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };



char pubkey[] = "demo";
char subkey[] = "demo";
char channel[] = "button-reply";
char uuid[] = "Arduino";

iotwrapper ard;

void do_something(String value){
          Serial.println("This is the received message: ");
          Serial.println(value);
        }

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
        String returnmessage;
	Ethernet.maintain();
        
        //Publish
	Serial.println("publishing a message");
        ard.sendArd(channel,"\"Hey There\"");
        

        //Subscribe
	Serial.println("waiting for a message");
        returnmessage = ard.connectArd(channel);
        
        
        // calbback function of sorts, to work with the received message
        do_something(returnmessage);
        
	Serial.println();
}
