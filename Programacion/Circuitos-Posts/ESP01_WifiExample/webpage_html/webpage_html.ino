/*------------------------------------------------------------------------------
  07/01/2018
  Author: Makerbro
  Platforms: ESP8266
  Language: C++/Arduino
  File: webserver_html.ino
  ------------------------------------------------------------------------------
  Description: 
  Code for YouTube video demonstrating how to use HTML weppages in a web 
  server's response.
  https://youtu.be/VNgFbQAVboA
  Do you like my videos? You can support the channel:
  https://patreon.com/acrobotic
  https://paypal.me/acrobotic
  ------------------------------------------------------------------------------
  Please consider buying products from ACROBOTIC to help fund future
  Open-Source projects like this! We'll always put our best effort in every
  project, and release all our design files and code for you to use. 
  https://acrobotic.com/
  https://amazon.com/acrobotic
  ------------------------------------------------------------------------------
  License:
  Please see attached LICENSE.txt file for details.
------------------------------------------------------------------------------*/
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;
uint8_t pin_led = 0;
char* ssid = "NEXTNGNR";
char* password = "11h1llw28";

char webpage[] PROGMEM = R"=====(
<html>
<head>
 <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
        html { 
            font-family: 'Montserrat', sans-serif;
            display: inline-block; 
            margin: 0px auto; 
            text-align: center;
            background-color: #142B43;
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
        .button2 {
        background-color: #00AEAE;
        }
        
        div.relative {
            position: relative;
            top: 400px;
            text-align: center;
        }
        h1{
            position: relative;
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
        
        body{
            margin: 0;
            padding: 0;
            -webkit-transition: 1s ease-in-out;
        }
        p {
            color: white;
        }
        
        .container{
            position:relative;
            margin-top: 60px;
        }
        
        .bulb{
            position: absolute;
            background-color: #CCE8FF;
            height: 250px;
            width: 240px;
            border-radius: 50%;
            left: 0;
            right: 0;
            border: solid #5a2b12 5px;
            margin: auto;
            -webkit-transition: 2s ease-in-out;
        }
        
        
        
        .filament1, .filament2{
            position: absolute;
            background-color: #5a2b12;
            height: 100px;
            width: 7px;
            left: 0;
            right: 40px;
            top: 180px;
            margin: auto;
            border-radius: 5px;
            -webkit-transform: rotate(-10deg);
            z-index: 1;
        }
        
        .filament2{
            right: 0;
            left: 30px;
            -webkit-transform: rotate(10deg);
        }
        
        .base-yellow{
            position: absolute;
            background-color: #CCE8FF;
            width: 100px;
            height: 50px;
            top: 230px;
            left: 0;
            right: 0;
            border-left: solid #5a2b12 5px;
            border-right: solid #5a2b12 5px;
            margin: auto;
            -webkit-transition: 2s ease-in-out;
        }
        
        .base{
            position: absolute;
            background-color: #c8c8c8;
            width: 100px;
            height: 60px;
            top: 280px;
            left: 0;
            right: 0;
            border-bottom-left-radius: 10px;
            border-bottom-right-radius: 10px;
            margin: auto;
            border: solid #5a2b12 5px;
        }
        
        .l1, .l2{
            background-color: #5a2b12;
            height: 5px;
            margin-top: 16px;
        }
  </style>
  <script>
      var isBulbOn=false;
      
      function bulb_on_off() {
          var bulb = document.getElementsByClassName("bulb")[0],
              base = document.getElementsByClassName("base-yellow")[0],
              body = document.getElementsByTagName("body")[0],
              blush = document.getElementsByClassName("blush-container")[0],
              lip_happy = document.getElementsByClassName("lips-happy")[0],
              lip_sad = document.getElementsByClassName("lips-sad")[0];
      
          if(isBulbOn)
              aoff();
          else
              aon();
      
          function aon() {
              isBulbOn=true;
              // body.style.backgroundColor="#555555";
              bulb.style.backgroundColor="yellow";
              bulb.style.boxShadow="0 0 40px #ffd309";
              base.style.backgroundColor="yellow";
              blush.style.opacity="1";
              lip_sad.style.opacity="0";
              lip_happy.style.opacity="1";
          }
      
          function aoff() {
              isBulbOn=false;
              // body.style.backgroundColor="#000000";
              bulb.style.backgroundColor="#CCE8FF";
              bulb.style.boxShadow="none";
              base.style.backgroundColor="#CCE8FF";
      
          }
      
      }
      
      function sinluz(){
          isBulbOn=true;
          bulb_on_off();
      }
      function luz(){
          isBulbOn=false;
          bulb_on_off();
      }
  
  </script>
</head>
<body>
<h1>NEXTNGNR</h1>
        <h2>Controlador IoT</h2>
             <div class="container" >
                <div class="bulb" >
                    <div class="filament1"></div>
                    <div class="filament2"></div>
                    <div class="base-yellow"></div>
                </div>
                <div class="base">
                    <div class="l1"></div>
                    <div class="l2"></div>
                </div>
            </div>
            <div class="relative">
            <p> Haga clic para encender o apagar el bombillo </p>
<form action="/toggl">
<p><button class="button" > Encender </button></p>
</form>
</div>
</body>
</html>
)=====";


char webpage2[] PROGMEM = R"=====(
<html>
<head>
 <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
        html { 
            font-family: 'Montserrat', sans-serif;
            display: inline-block; 
            margin: 0px auto; 
            text-align: center;
            background-color: #142B43;
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
        .button2 {
        background-color: #00AEAE;
        }
        
        div.relative {
            position: relative;
            top: 400px;
            text-align: center;
        }
        h1{
            position: relative;
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
        
        body{
            margin: 0;
            padding: 0;
            -webkit-transition: 1s ease-in-out;
        }
        p {
            color: white;
        }
        
        .container{
            position:relative;
            margin-top: 60px;
        }
        
        .bulb{
            position: absolute;
            background-color: yellow;
            height: 250px;
            width: 240px;
            border-radius: 50%;
            left: 0;
            right: 0;
            border: solid #5a2b12 5px;
            margin: auto;
            -webkit-transition: 2s ease-in-out;
        }
        
        
        
        .filament1, .filament2{
            position: absolute;
            background-color: #5a2b12;
            height: 100px;
            width: 7px;
            left: 0;
            right: 40px;
            top: 180px;
            margin: auto;
            border-radius: 5px;
            -webkit-transform: rotate(-10deg);
            z-index: 1;
        }
        
        .filament2{
            right: 0;
            left: 30px;
            -webkit-transform: rotate(10deg);
        }
        
        .base-yellow{
            position: absolute;
            background-color: yellow;
            width: 100px;
            height: 50px;
            top: 230px;
            left: 0;
            right: 0;
            border-left: solid #5a2b12 5px;
            border-right: solid #5a2b12 5px;
            margin: auto;
            -webkit-transition: 2s ease-in-out;
        }
        
        .base{
            position: absolute;
            background-color: #c8c8c8;
            width: 100px;
            height: 60px;
            top: 280px;
            left: 0;
            right: 0;
            border-bottom-left-radius: 10px;
            border-bottom-right-radius: 10px;
            margin: auto;
            border: solid #5a2b12 5px;
        }
        
        .l1, .l2{
            background-color: #5a2b12;
            height: 5px;
            margin-top: 16px;
        }
  </style>
  <script>
      var isBulbOn=false;
      
      function bulb_on_off() {
          var bulb = document.getElementsByClassName("bulb")[0],
              base = document.getElementsByClassName("base-yellow")[0],
              body = document.getElementsByTagName("body")[0],
              blush = document.getElementsByClassName("blush-container")[0],
              lip_happy = document.getElementsByClassName("lips-happy")[0],
              lip_sad = document.getElementsByClassName("lips-sad")[0];
      
          if(isBulbOn)
              aoff();
          else
              aon();
      
          function aon() {
              isBulbOn=true;
              // body.style.backgroundColor="#555555";
              bulb.style.backgroundColor="yellow";
              bulb.style.boxShadow="0 0 40px #ffd309";
              base.style.backgroundColor="yellow";
              blush.style.opacity="1";
              lip_sad.style.opacity="0";
              lip_happy.style.opacity="1";
          }
      
          function aoff() {
              isBulbOn=false;
              // body.style.backgroundColor="#000000";
              bulb.style.backgroundColor="#CCE8FF";
              bulb.style.boxShadow="none";
              base.style.backgroundColor="#CCE8FF";
      
          }
      
      }
      
      function sinluz(){
          isBulbOn=true;
          bulb_on_off();
      }
      function luz(){
          isBulbOn=false;
          bulb_on_off();
      }
  
  </script>
</head>
<body>
<h1>NEXTNGNR</h1>
        <h2>Controlador IoT</h2>
             <div class="container" >
                <div class="bulb" >
                    <div class="filament1"></div>
                    <div class="filament2"></div>
                    <div class="base-yellow"></div>
                </div>
                <div class="base">
                    <div class="l1"></div>
                    <div class="l2"></div>
                </div>
            </div>
            <div class="relative">
            <p> Haga clic para encender o apagar el bombillo </p>
<form action="/toggle">
<p><button class="button"> Apagar </button></p>
</form>
</div>
</body>
</html>
)=====";


void setup()
{
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/html","<h1>Hello World!</h1>");});
  server.on("/toggle",toggleLED);
  server.on("/toggl",toggleLED2);

  server.begin();
}

void loop()
{
  server.handleClient();
}

void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send_P(200,"text/html", webpage);
}
void toggleLED2()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send_P(200,"text/html", webpage2);
}
