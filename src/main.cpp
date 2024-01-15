#include <Arduino.h>
#include <Wire.h>
#include <HCSR04.h>
#include <U8g2lib.h>

// put function declarations here:
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 
byte triggerPin = 4;
byte echoPin = 5;

double len_us_cm;

void u8g2_update();
void ultrasonic_update();

void setup() {
  // put your setup code here, to run once:
  u8g2.begin(); 
  HCSR04.begin(triggerPin, echoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  ultrasonic_update();
  u8g2_update();
}

void u8g2_update() {
  u8g2.firstPage();
		do {
			u8g2.setFont(u8g2_font_logisoso24_tn  );
			u8g2.setCursor(18,24);
			u8g2.print(len_us_cm);
			//u8g2.drawStr(80,24,"2.8");

		} while ( u8g2.nextPage() );
}

void ultrasonic_update() {
    double* distances = HCSR04.measureDistanceCm();
    len_us_cm = distances[0];
}