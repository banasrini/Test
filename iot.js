(function () {
            var button = PUBNUB.$('devicebutton');
            var pubnub = PUBNUB.init({
                publish_key: 'demo',
                subscribe_key: 'demo'
            });

            // sending a reply to the device that is online, channel : iot-device. change the channel to 
            //publish in as iot-device in both the arduino and python code for raspberry pi. 
            
            pubnub.bind('click', button, function () {
                pubnub.publish({
                    channel: 'iot-device',
                    presence: function(m){console.log(m)},
                    message: $('#hellodevice').val() // the message that we want to send to the online device
                });
            });

			// subscribing to the channel above, to see if the device is receiving my message.
            pubnub.subscribe({
                channel: 'iot-device',
                message: hello_to_device
            });

            // Printing my own message in my page
            function hello_to_device(message) {
                $('#chat').append("<div class='bubbledRight'>" + message + "</div>");
                
            }

            // subscribing to the channels that devices send messages to. Let this universally be called device-discovery
            pubnub.subscribe({
                channel: 'device-discovery',
                presence: function(m){console.log(m)},
                message: message-from-devices
            });
            
 			 pubnub.here_now({
     			channel : 'iot-device',
     			callback : function(m){console.log(m)},
     			state:true
 			});
 			
            
            // action when message received from the server
            function message-from-devices(message) {
                $('#chat').append("<div class='bubbledLeft'>" + message + "</div>");
          
            }
        
        	   
        
        })();
