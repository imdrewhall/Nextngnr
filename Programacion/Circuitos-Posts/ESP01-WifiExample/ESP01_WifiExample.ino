/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>


// Replace with your network credentials
const char* ssid     = "H1LLSM3TH";
const char* password = "11h1llw28";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";

// Assign output variables to GPIO pins
const int output5 = 0;
const int output4 = 4;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);

  // Set outputs to LOW
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
           if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(output5, HIGH);
           } else if (header.indexOf("GET /5/off") >= 0) {
             // delay(700);
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(output5, LOW);
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(output4, HIGH);
            } else if (header.indexOf("GET /4/off") >= 0) {
              //delay(700);
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(output4, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            //CSS to style the on/off buttons 
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<style>html {font-family: 'Montserrat', sans-serif; display: inline-block; margin: 0px auto; text-align: center; background: url(fondo.jpg) no-repeat center center fixed; -webkit-background-size: cover; -moz-background-size: cover; -o-background-size: cover; background-size: cover;}");
            client.println(".button { background-color: #2894FF; border: none; color: black; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #00AEAE;}");
            client.println("div.relative {position: relative;top: 400px;text-align: center;}");
            client.println("h1{position: relative; color: white; width: 400px; text-align: center; box-shadow: 4px 4px 5px black;}");
            client.println("h2{color: white; width: 400px; text-align: center;}");
            client.println("body{margin: 0; padding: 0; -webkit-transition: 1s ease-in-out;}");
            client.println("p{color: white;}");
            client.println(".container{position:relative; margin-top: 60px;}");
            client.println(".bulb{ position: absolute; background-color: #CCE8FF; height: 250px; width: 240px; border-radius: 50%; left: 0; right: 0; border: solid #5a2b12 5px; margin: auto; -webkit-transition: 2s ease-in-out;}");
            client.println(".filament2{ right: 0; left: 30px; -webkit-transform: rotate(10deg);}");
            client.println(".base-yellow{ position: absolute; background-color: #CCE8FF; width: 100px; height: 50px;  top: 230px; left: 0; right: 0; border-left: solid #5a2b12 5px; border-right: solid #5a2b12 5px; margin: auto; -webkit-transition: 1s ease-in-out;}");
    
            client.println(".base{ position: absolute; background-color: #c8c8c8; width: 100px;  height: 60px; top: 280px; left: 0;  right: 0; border-bottom-left-radius: 10px; border-bottom-right-radius: 10px; margin: auto; border: solid #5a2b12 5px;}");
            client.println(".l1, .l2{background-color: #5a2b12; height: 5px; margin-top: 16px;}</style>");
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<script>var isBulbOn=false; function bulb_on_off() {");
            client.println("var bulb = document.getElementsByClassName(\"bulb\")[0], base = document.getElementsByClassName(\"base-yellow\")[0],");
            client.println("base = document.getElementsByClassName(\"base-yellow\")[0], body = document.getElementsByTagName(\"body\")[0],");
            client.println("blush = document.getElementsByClassName(\"blush-container\")[0];");
            client.println("if(isBulbOn)");
            client.println("off();");
            client.println("else");
            client.println("on();");
            client.println("function on() { isBulbOn=true; bulb.style.backgroundColor=\"yellow\"; bulb.style.boxShadow=\"0 0 40px #ffd309\";");
            client.println("base.style.backgroundColor=\"yellow\"; blush.style.opacity=\"1\";");
            client.println("function off() {");
            client.println("isBulbOn=false;");
            client.println("bulb.style.backgroundColor=\"#CCE8FF\";");
            client.println("bulb.style.boxShadow=\"none\";base.style.backgroundColor=\"#CCE8FF\";}}");
            client.println("function sinluz(){isBulbOn=true;  bulb_on_off();}");
            client.println("function luz(){ isBulbOn=false; bulb_on_off();}");
            client.println("</script></head>");

            
            client.println("<body><h1>NEXTNGNR</h1><h2>Controlador IoT</h2><div class=\"container\">");
            client.println("<div class=\"bulb\"><div class=\"filament1\"></div><div class=\"filament2\"></div><div class=\"base-yellow\"></div></div>");
            client.println("<div class=\"base\"><div class=\"l1\"></div><div class=\"l2\"></div></div></div>");
            
              // BUTTONS
            client.println("<div class=\"relative\">");
            
            // Display current state, and ON/OFF buttons for GPIO 5  
             // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p> Presione para encender </p>");
            // If the output5State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\" onclick=\"luz();\">TURN ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\" onclick=\"sinluz();\">TURN OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 4  
            
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}     
