
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 21, /* data=*/ 22);

void setup(void)
{
	u8g2.begin();
	u8g2.enableUTF8Print();
	u8g2.setFont(u8g2_font_unifont_t_cyrillic);
	//u8g2.setFont(u8g2_font_7x13_t_cyrillic);
	//u8g2.setFont(u8g2_font_cu12_t_cyrillic);
	u8g2.setFontDirection(0);

}
int count = 0;

void loop(void)
{
	count++;
	u8g2.clearBuffer();

	delay(1000);

	u8g2.setCursor(0, 15);
	u8g2.print("Hi! Привет!");
	u8g2.print(count);
	u8g2.sendBuffer();

	delay(2000);

	u8g2.setCursor(20, 30);
	u8g2.print("-= Иван =- ");
	u8g2.sendBuffer();
	delay(2000);
}
