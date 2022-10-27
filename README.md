# Raproto-Arduino
Code that connects Arduino Nano 33 IoT devices to the Raproto Thingsboard Dashboard.

Download libraries: 
ArduinoMqttClient.h
WiFiNINA.h

Enter: 
1. Network name
2. Network password
3. Broker address 
4. publish and subscribe topics (add more as needed) 
5. Username and Password 
6. Client ID 

Edit: 
1. Main code. In this example, main code is happening in void loop() but can be moved outside elsewhere if looping is undesirable. 

Note: this code uses port 8883. 
Note: Username, password, client ID, etc. requirements will vary based on your setup. 

To run, compile and upload code to Arduino Nano 33 IoT. 
