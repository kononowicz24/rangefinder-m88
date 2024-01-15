#include <Arduino.h>
#include <Wire.h>
#include <Ultrasonic.h>
#include <U8g2lib.h>

// put function declarations here:
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 
Ultrasonic ultrasonic(0,1 , 20000UL);

int len_us_cm = 0;

void u8g2_update();
void ultrasonic_update();

void setup() {
  // put your setup code here, to run once:
  u8g2.begin(); 
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
			u8g2.drawStr(0,8,"t: ");
			u8g2.setCursor(18,24);
			u8g2.print(len_us_cm);
			//u8g2.drawStr(80,24,"2.8");

		} while ( u8g2.nextPage() );
}

void ultrasonic_update() {
  len_us_cm = ultrasonic.read();
}