#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <ESPmDNS.h>
#else
#error "Board not found"
#endif

#include <WebSocketsServer.h>

#include <ArduinoJson.h>
#include <DHT.h> //DHT and Adafruit Sensor library(https://github.com/adafruit/Adafruit_Sensor)
#include <Ticker.h> //https://github.com/sstaub/Ticker

#define DHTPIN 4
#define LED1 13
#define LED2 12
#define SOILA 32
#define SOILB 35
#define SOILC 34

#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);

void send_sensor();

Ticker timer;
/////////////////////////////////////////////////////////////////////////////////////
char webpage[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
<head>
 <meta name="viewport" content="width=device-width, initial-scale=1.0">

 <style>
        html { 
            font-family: 'Montserrat', sans-serif;
            display: inline-block; 
            margin: 0px auto; 
            text-align: center;
            background-color: #076FD7;
            -webkit-background-size: cover;
            -moz-background-size: cover;
            -o-background-size: cover;
            background-size: cover;   
        
        }
        .button { 
            background-color: #FF4900; 
            border: none; 
            color: black; 
            padding: 16px 40px;
            text-decoration: none;
            font-size: 30px; 
            margin: 2px; 
            cursor: pointer;
            border-radius: 300px;
        }
        
        div.relative {
            position: relative;
            top: 400px;
            text-align: center;
        }
        h1{
            color: white;
            width: 400px;
            text-align: center;
            box-shadow: 4px 4px 5px black;
        }
        
        h2{
            color: white;
            width: 400px;
            text-align: center;
        
        }
        h3{
            color: white;
            text-align: center;
        
        }

        h4{
            color: #076FD7;
            text-align: center;
        
        }
        body{
            margin: 0;
            padding: 0;
            -webkit-transition: 1s ease-in-out;
        }
    </style>
<script>

var connection = new WebSocket('ws://'+location.hostname+':81/');

var button_1_status = 1;
var button_2_status = 0;
var temp_data = 0;
var hum_data = 0;
var soila_data = 0;
var soilb_data = 0;
var soilc_data = 0;

connection.onmessage = function(event){

  var full_data = event.data;
  console.log(full_data);
  var data = JSON.parse(full_data);
  temp_data = data.temp;
  hum_data = data.hum;

  soila_data = data.soila;
  soilb_data = data.soilb;
  soilc_data = data.soilc;
  
  document.getElementById("temp_meter").value = temp_data;
  document.getElementById("temp_value").innerHTML = temp_data;
  document.getElementById("hum_meter").value = hum_data;
  document.getElementById("hum_value").innerHTML = hum_data;

  document.getElementById("soila_meter").value = soila_data;
  document.getElementById("soila_value").innerHTML = soila_data;
  document.getElementById("soilb_meter").value = soilb_data;
  document.getElementById("soilb_value").innerHTML = soilb_data;
  document.getElementById("soilc_meter").value = soilc_data;
  document.getElementById("soilc_value").innerHTML = soilc_data;
}

function button_1_on()
{
   button_1_status = 0; 
  console.log("LED 1 is ON");
  send_data();
}

function button_1_off()
{
  button_1_status = 1;
console.log("LED 1 is OFF");
send_data();
}


function send_data()
{
  var full_data = '{"LED1" :'+button_1_status+'}';
  connection.send(full_data);
}


</script>
</head>
<body>

<center>
<h1> NEXTNGNR </h1>
<h2> Hydropnk IoT </h2>
<h3> Control de Bomba </h3>
<p><button class="button" onclick= "button_1_on()" >On</button><button class="button" onclick="button_1_off()" >Off</button></p>


<div style="text-align: center;">
<h3>Temperatura</h3><meter value="2" min="0" max="100" id="temp_meter"> </meter><h4 style="display: inline-block;"> aa  </h4><h3 id="temp_value" style="display: inline-block;"> 2 </h3>
<h3>Humedad del Ambiente</h3><meter value="2" min="0" max="100" id="hum_meter">  </meter><h4 style="display: inline-block;"> aa  </h4><h3 id="hum_value" style="display: inline-block;"> 2 </h3>
</div>
<h2> Humedad en el sustrato </h2>
<div style="text-align: center;">
<h3>Medidor 1</h3><meter value="2" min="0" max="100" id="soila_meter"> </meter><h4 style="display: inline-block;">  aa </h4><h3 id="soila_value" style="display: inline-block;"> 2 </h3>
<h3>Medidor 2</h3><meter value="2" min="0" max="100" id="soilb_meter"> </meter><h4 style="display: inline-block;"> aa  </h4><h3 id="soilb_value" style="display: inline-block;"> 2 </h3>
<h3>Medidor 3</h3><meter value="2" min="0" max="100" id="soilc_meter"> </meter><h4 style="display: inline-block;"> aa  </h4><h3 id="soilc_value" style="display: inline-block;"> 2 </h3>
</div>
</center>

</body>
</html>

)=====";
///////////////////////////////////////////////////////////////////////////////////////////////
// ipaddress/led1/on
//ipaddress/led1/off

// ipaddress/led2/on
//ipaddress/led2/off
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80); // server port 80
WebSocketsServer websockets(81);

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Page Not found");
}


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch (type) 
  {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = websockets.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] get Text: %s\n", num, payload);
      String message = String((char*)( payload));
      Serial.println(message);

      
     DynamicJsonDocument doc(200);
    // deserialize the data
    DeserializationError error = deserializeJson(doc, message);
    // parse the parameters we expect to receive (TO-DO: error handling)
      // Test if parsing succeeds.
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  int LED1_status = doc["LED1"];
  digitalWrite(LED1,LED1_status);





  }
}

void setup(void)
{
  
  Serial.begin(115200);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  dht.begin();
  
  WiFi.softAP("drewsms", "");
  Serial.println("softap");
  Serial.println("");
  Serial.println(WiFi.softAPIP());


  if (MDNS.begin("ESP")) { //esp.local/
    Serial.println("MDNS responder started");
  }



  server.on("/", [](AsyncWebServerRequest * request)
  { 
   
  request->send_P(200, "text/html", webpage);
  });

   server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED1,LOW);
  request->send_P(200, "text/html", webpage);
  });

  server.onNotFound(notFound);

  server.begin();  // it will start webserver
  websockets.begin();
  websockets.onEvent(webSocketEvent);
  timer.attach(2,send_sensor);

}


void loop(void)
{
 websockets.loop();
}

void send_sensor()
{
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float sa = map(analogRead(SOILA),1289,3723,100,0);
  // Read temperature as Celsius (the default)
  float sb = map(analogRead(SOILB),1289,3723,100,0);
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float sc = map(analogRead(SOILC),1289,3723,100,0);
  
    if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // JSON_Data = {"temp":t,"hum":h}
  String JSON_Data = "{\"temp\":";
         JSON_Data += t;
         JSON_Data += ",\"hum\":";
         JSON_Data += h;
         JSON_Data += ",\"soila\":";
         JSON_Data += sa;
         JSON_Data += ",\"soilb\":";
         JSON_Data += sb;
         JSON_Data += ",\"soilc\":";
         JSON_Data += sc;
         JSON_Data += "}";
         
   Serial.println(JSON_Data);     
  websockets.broadcastTXT(JSON_Data);
}
