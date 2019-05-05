#include <ESP8266WiFi.h>

const char* ssid = "Prashant";
const char* password = "1234567890~!@#$%^&*()";

const char* host = "192.168.1.6";

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.println();

  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);

  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
   }
  Serial.println("WiFi connected");
  Serial.print("IP Address =");
  Serial.println(WiFi.localIP());
}

void loop()
{
  delay(5000);
  Serial.print("Connecting to");
  Serial.println(host);
  WiFiClient client;
  const int  httpPort =80;
  if(!client.connect(host,httpPort))
  {
    Serial.println("Connection Failed");
    return ;
  }
   String url="/receiver.php?value1=344&value2=244";
   
   Serial.print("requesting URL: ");
   Serial.println(url);
   client.print(String("GET ")+url+ "\r\n"+
   "Host: " + host +"\r\n"+
   "Connection  : close\r\n\r\n");
   unsigned long timeout = millis();
   while(client.available()==0)
   {
    if(millis()-timeout>5000)
    {
      Serial.println(">>>Client Timeout");
      client.stop();
      return ;
    }
   }
   while(client.available())
   {
     String line = client.readStringUntil('\r');
     Serial.println(line);
   }
   delay(2000);
}
