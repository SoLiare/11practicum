#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "AonMerauqs";
const char* password = "fuckyou!";

String url_to_str(String url){
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      return payload;
    }
    else {
      return "error";
    }
    http.end();   //Close connection
  }
  return "";
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

String timing, alarm, check;

void loop() {
  timing = url_to_str("http://practicum.srakrn.me/time.php");
  alarm = url_to_str("http://practicum.srakrn.me/time.txt");
  check = url_to_str("http://practicum.srakrn.me/switch.txt");
  if(timing == alarm){
    digitalWrite(2, HIGH);
    Serial.println("high"); 
  }
  if(timing != alarm)
  {
    digitalWrite(2, LOW);
    digitalWrite(13, HIGH);
  }
  if(check == "X")
  {
    digitalWrite(13, HIGH);
  }
  if(check == "O")
  {
    digitalWrite(13, LOW);
  }
  Serial.println(timing);
  Serial.println(alarm);
  Serial.println(check);
}
