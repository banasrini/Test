from Pubnub import Pubnub
import string
import time
import random
import uuid


class IOTWrapper(object):
    def __init__(self, pubnub):
        self.pubnub = pubnub

    def receive(self,message):
        print(message)
        
    
    def send(self, channel, message):
        self.pubnub.publish({
            'channel' : channel,
            'message' : message})

    def connect(self, channel):
        self.pubnub.subscribe({
            'channel' : channel,
            'callback' : self.receive
        })

   
