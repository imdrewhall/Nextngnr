
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display


Adafruit_SSD1306 display(128, 64);  // Create display


#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font
#include <Fonts/FreeMonoOblique12pt7b.h>  // Add a custom font
#include <Fonts/FreeMonoBoldOblique9pt7b.h>  // Add a custom font

int Variable1; 

void setup() {

  delay(100);  // This delay is needed to let the display to initialize

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
 
  display.clearDisplay();  // Clear the buffer

  display.setTextColor(WHITE);  // Set color of the text

  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3

  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).

  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)

}

void loop() {
  
  Variable1++;  // Increase variable by 1
  delay(50);
  if(Variable1 > 150)  // If Variable1 is greater than 150
  {
    Variable1 = 0;  // Set Variable1 to 0
  }

  char string[10];  // Create a character array of 10 characters
  // Convert float to a string:
  
  //dtostrf(Variable1, 3, 0, string);
    
  display.clearDisplay();  // Clear the display so we can refresh


  display.setFont(&FreeMonoBoldOblique9pt7b);  // Set a custom font
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0


  // Print text:
  display.setCursor(0, 10);  // (x,y)
  display.println("Bellacosa");  // Text or value to print
  display.setCursor(0, 25);  // (x,y)
  display.println("Distancia");  // Text or value to print

  // Draw rectangle:
  //display.drawRect(79, 0, 49, 27, WHITE);  // Draw rectangle (x,y,width,height,color)
                                           // It draws from the location to down-right
   
  display.setFont(&FreeMonoBold12pt7b);  // Set a custom font
  
  // Print variable with left alignment:
  //display.setCursor(83, 20);  // (x,y)
  //display.println(Variable1);  // Text or value to print




  // Draw rounded rectangle:
  display.drawRoundRect(69, 37, 49, 27, 8, WHITE);  // Draw rounded rectangle (x,y,width,height,radius,color)
                                                    // It draws from the location to down-right

  // Print variable with right alignment:
//  display.setCursor(74, 57);  // (x,y)
//  display.println(string);  // Text or value to print

  
  display.display();  // Print everything we set previously



  
}
