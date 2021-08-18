#include <ESP8266WiFi.h>        // Include the Wi-Fi library

const char* ssid     = "PRECISE";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "precisely";     // The password of the Wi-Fi network

#include<SoftwareSerial.h>
SoftwareSerial client(2,3); //RX, TX

String webpage="";
int i=0,k=0;
String readString;
int x=0;

boolean No_IP=false;
String IP="";
char temp1='0';

String name="<p>Circuit Digest</p>";
String dat="<p>Data Received Successfully.....</p>";

void setup() {
Serial.begin(115200);         // Start the Serial communication to send messages to the computer
delay(10);
Serial.println('\n');
WiFi.begin(ssid, password);             // Connect to the network
Serial.print("Connecting to ");
Serial.print(ssid); Serial.println(" ...");

int i = 0;
while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
}

Serial.println('\n');
Serial.println("Connection established!");
Serial.print("IP address:\t");
Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop()

{

k=0;

while(k<1000)
{
    k++;
   while(client.available())
   {
    if(client.find("0,CONNECT"))
    {
      Serial.println("Start Printing");
      Send();
      Serial.println("Done Printing");
      delay(1000);
    }
}
}
}


void sendwebdata(String webPage)
{
    int ii=0;
     while(1)
     {
      unsigned int l=webPage.length();
      Serial.print("AT+CIPSEND=0,");
      client.print("AT+CIPSEND=0,");
      Serial.println(l+2);
      client.println(l+2);
      delay(100);
      Serial.println(webPage);
      client.println(webPage);
      while(client.available())
      {
        Serial.print(analogRead(A0));
        if(client.find("OK"))
        {
          ii=11;
          break;
        }
      }
      if(ii==11)
      break;
      delay(100);
     }
}


void Send()
{
      webpage = " ";
      sendwebdata(webpage);
      webpage=name;
      webpage+=dat;
      sendwebdata(webpage);
      delay(1000);
     webpage = " ";
   
     sendwebdata(webpage);
     client.println("AT+CIPCLOSE=0");
}
