from Pubnub import Pubnub
from IoT_wrapper import iotwrapper

pi = iotwrapper(publish_key = 'demo', subscribe_key = 'demo', uuid = 'PI', receiver ='do_something')

channel = 'button-reply'
message = "hello from pi"

def receiver(message):
  print(message)
  
pi.send(channel, message)

pi.connect(channel, receiver)


  




