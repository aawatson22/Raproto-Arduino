#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>

//adapted from https://github.com/arduino-libraries/ArduinoMqttClient/blob/master/examples/WiFiAdvancedCallback/WiFiAdvancedCallback.ino
//additional reference: https://gist.github.com/virgilvox/ffe1cc08a240db9792d3

///////please enter WiFi network and password
char ssid[] = "";        // network (name)
char pass[] = "";    // network password (use for WPA, or use as key for WEP)

WiFiSSLClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = ""; //broker address 
int        port     = 8883;
const char topicPUB[]  = ""; //publish topic 
const char topicSUB[]  = ""; //subscribe topic 

const char USERNAME[] = ""; //broker username 
const char PASSWORD[] = ""; //broker password

const char client_id[] = ""; //client id 

//setup code for WiFi and MQTT 
void setup() {
      //serial initialization
  Serial.begin(9600);

  // WiFi connection
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("connected to the network");
  Serial.println();

  mqttClient.setId(client_id); 
  
  mqttClient.setUsernamePassword(USERNAME, PASSWORD);

  Serial.print("Attempting connection to MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();

}

//looping code -- example here sends HR values from 0 to 100 in iterations of 5 
void loop() {
  mqttClient.poll();
  
  String payloadPUB;
  double num = 0;

  while (num < 100){

    payloadPUB = "{\"HR\":"+String(num, 6)+"}";
  
    Serial.print("Sending message to topic: ");
    Serial.println(topicPUB);
    Serial.println(payloadPUB);
  
    bool retained = false;
    int qos = 1;
    bool dup = false;
  
    mqttClient.beginMessage(topicPUB, payloadPUB.length(), retained, qos, dup);
    mqttClient.print(payloadPUB);
    mqttClient.endMessage();

    num = num+5;
  }
}
