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
  String connectArd(const char *channel);
  bool printArd(const char *message);
  
  
};
  

bool iotwrapper::initvar(const char *publish_key, const char *subscribe_key, const char *uuid){
  
  PubNub.begin(publish_key,subscribe_key);
  PubNub.set_uuid(uuid);
}

bool iotwrapper::sendArd(const char *channel, const char *message){
  EthernetClient *client;
  client = PubNub.publish(channel,message);
  return client;
}

String iotwrapper::connectArd(const char *channel){
  
  String message = "";
  int i = 0;
  PubSubClient *pclient = PubNub.subscribe(channel);
	if (!pclient) {
		return 0;
	}
	
  while (pclient->wait_for_data()) {
		char c = pclient->read();
                message += c;
	}


	pclient->stop();
	Serial.println();
  return message;
  
}
  
