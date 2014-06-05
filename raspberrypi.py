from Pubnub import Pubnub
from IoT_wrapper import IOTWrapper

pubnub = Pubnub( 'demo', 'demo', None, False)

pi = IOTWrapper(pubnub)

uuid = 'PI';
print("My UUID is: "+uuid)
pubnub.uuid = uuid;
channel = 'button-reply'
message = "hello from pi"


pi.send(channel, message)
print("Sending message on channel")

print("Listening for messages on channel")
pi.connect(channel)


  




