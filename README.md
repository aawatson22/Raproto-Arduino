# Raproto-Arduino
Code that connects Arduino Nano 33 IoT device to the Raproto Thingsboard Dashboard.

Download libraries: 
ArduinoMqttClient.h
WiFiNINA.h

Enter: 
1. Network name
2. Network password
3. Broker address 
4. Publish and Subscribe topics (add more as needed) 
5. Username and Password 
6. Client ID 

Edit: 
1. Main code. In this example, main code is happening in void loop() but can be moved outside if looping is undesirable. 

Note: this code uses port 8883. 
Note: Username, password, client ID, etc. requirements will vary based on your setup. 

To run:
1. Compile and upload code to Arduino Nano 33 IoT. 
