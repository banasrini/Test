from Pubnub import Pubnub
import string
import time
import random
import uuid



class iotwrapper(object):
    def __init__(self, publish_key,
        subscribe_key,uuid, receiver):

        self.publish_key = publish_key
        self.subscribe_key = subscribe_key
        self.uuid = uuid
        self.receiver = receiver
        self.pubnub = Pubnub( 'demo', 'demo', None, False)
        self.pubnub.uuid = self.uuid
    
    
    
    def send(self, channel, message):
        print("Sending message on %s channel" % channel)
        self.pubnub.publish({
            'channel' : channel,
            'message' : message})

    def connect(self, channel, receiver):
        print("Listening for messages on %s channel" % channel)
        self.pubnub.subscribe({
            'channel' : channel,
            'callback' : self.receiver
        })

   
