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

void setup() {
  WiFi.mode(WIFI_OFF);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(500);
}

void loop() { 
  digitalWrite(LED_BUILTIN, HIGH);
  display.clearDisplay();
  mTime = millis();
  
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.println(mTime);

  if (digitalRead(button1) == LOW)
  {
    display.setCursor(0, 10);
    display.println("Y");
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (digitalRead(button2) == LOW)
  {
    display.setCursor(10 , 10);
    display.println("N");
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (digitalRead(button3) == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  display.display();
}
