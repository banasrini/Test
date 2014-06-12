from Pubnub import Pubnub
from IoT_wrapper import iotwrapper

pi = iotwrapper(publish_key = 'demo', subscribe_key = 'demo', uuid = 'PI')

channel = 'button-reply'
message = "hello from pi"

def do_something(message):
  print(message)
  
pi.send(channel, message)

pi.connect(channel, do_something)


  




