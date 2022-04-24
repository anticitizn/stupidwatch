#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

int button1 = 3;
int button2 = 1;
int button3 = 0;

unsigned long mTime;
unsigned long pressedTime;
int hours;
int minutes;
int seconds;
int milliseconds;

char upperDisplay[6];
char lowerDisplay[6];

void setup() {
  WiFi.mode(WIFI_OFF); // save us some power
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(500); // the display needs a bit of time to start
}

void loop() { 
  digitalWrite(LED_BUILTIN, HIGH);
  display.clearDisplay();
  mTime = millis() - pressedTime;
  hours = (int) mTime / 3600000;
  minutes = (int) (mTime - hours * 3600000) / 60000;
  seconds = (int) (mTime - hours * 3600000 - minutes * 60000) / 1000;
  milliseconds = (int) (mTime - hours * 3600000 - minutes * 60000 - seconds * 1000) / 10;

  sprintf(upperDisplay, "%02d:%02d", hours, minutes);
  sprintf(lowerDisplay, "%02d.%02d", seconds, milliseconds);
  
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.print(upperDisplay);
  display.print('\n');
  display.print(lowerDisplay);

  if (digitalRead(button1) == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
    pressedTime = millis();
  }

  if (digitalRead(button2) == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (digitalRead(button3) == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  display.display();
}
