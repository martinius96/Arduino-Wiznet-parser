#include <SPI.h>
#include <Ethernet2.h>
int led = 6;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //physical MAC address
char serverName[] = "www.arduino.php5.sk"; // webserver
IPAddress ip(192, 168, 1, 254); //change to your LAN settings.
EthernetClient client;
String readString;
int x=0; //pocitadlo riadkov
char lf=10; //line feed character
void setup(){
pinMode(led, OUTPUT);
 if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
  Serial.begin(9600); 
}

void loop(){
if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /PHP_cz/preklady.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  //close 1.1 persistent connection  
    client.println(); //end of get request
  } 
  else {
    Serial.println("Connection unsucessful!!!!"); 
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //wait for datas
  while (client.connected() || client.available()) { //parsing
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //full http header
    if (c==lf) x=(x+1); //count 
    else if (x==12) readString += c; //our variable

   } 
if(readString=="Zapni"){
  digitalWrite(led, HIGH); 
  Serial.println("Turn on output");
  }else if(readString=="Vypni"){
  digitalWrite(led, LOW);  
Serial.println("Turn off output");
    }
    else{
 Serial.println("Unsuported variable! Check count of variable");
 }
  
  readString = ("");
  x=0;
  client.stop(); //stop connection
  delay(5000); //wait
} 
