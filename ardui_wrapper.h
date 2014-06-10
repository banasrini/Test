#include "PubNub.h"
#include <SPI.h>
#include <Ethernet.h>



class iotwrapper{
  public:
  
  const char *publish_key;
  const char *subscribe_key;
  const char *uuid;
  const char *channel;
  const char *message;
  
  bool initvar(const char *publish_key, const char *subscribe_key, const char *uuid);
  bool sendArd(const char *channel, const char *message);
  bool connectArd(const char *channel);
  bool printArd(const char *message);
  
  
};
  

bool iotwrapper::initvar(const char *publish_key, const char *subscribe_key, const char *uuid){
  
  PubNub.begin(publish_key,subscribe_key);
  PubNub.set_uuid(uuid);
  Serial.println("initialized the variables");
}

bool iotwrapper::sendArd(const char *channel, const char *message){
  EthernetClient *client;
  client = PubNub.publish(channel,message);
 
Serial.println(" published a message ");
return client;
}

bool iotwrapper::connectArd(const char *channel){
  PubSubClient *pclient = PubNub.subscribe(channel);
	if (!pclient) {
		return 0;
	}
  while (pclient->wait_for_data()) {
		char c = pclient->read();
		Serial.print(c);
	}
	pclient->stop();
	Serial.println();
  
}
  
