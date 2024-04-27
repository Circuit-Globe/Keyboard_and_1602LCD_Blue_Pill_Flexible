/*
 * LCD1602.h
 *
 *  Created on: Apr 27, 2024
 *      Author: dhara
 */

#ifndef LCD1602_H_
#define LCD1602_H_




#include "STM32F103IO.h"


volatile uint8_t lcd_RS, lcd_EN, lcd_D4, lcd_D5, lcd_D6, lcd_D7;





void Send_4_bit(volatile uint8_t bits){

	volatile uint8_t bit4, bit5, bit6, bit7;

	bit4 = (bits >> 4) & 1;
	bit5 = (bits >> 5) & 1;
	bit6 = (bits >> 6) & 1;
	bit7 = (bits >> 7) & 1;

	GPIO_write(lcd_D4, bit4);
	GPIO_write(lcd_D5, bit5);
	GPIO_write(lcd_D6, bit6);
	GPIO_write(lcd_D7, bit7);
}



void LCD_Command (volatile uint8_t cmnd)
{
	Send_4_bit(cmnd & 0xF0);           // Send upper nibble
	GPIO_write(lcd_EN, 1);             // lcd_en = 1, lcd_rs = 0
	GPIO_write(lcd_RS, 0);
	delay_us(50);
	GPIO_write(lcd_EN, 0);             // lcd_en = 0, lcd_rs = 0
	GPIO_write(lcd_RS, 0);
	delay_us(50);

	Send_4_bit((cmnd & 0x0F) << 4);    // Send lower nibble
	GPIO_write(lcd_EN, 1);             // lcd_en = 1, lcd_rs = 0
	GPIO_write(lcd_RS, 0);
	delay_us(50);
	GPIO_write(lcd_EN, 0);             // lcd_en = 0, lcd_rs = 0
	GPIO_write(lcd_RS, 0);
	delay_us(50);
}



void LCD_Char(volatile uint8_t data)
{
	Send_4_bit(data & 0xF0);           // Send upper nibble
	GPIO_write(lcd_EN, 1);             // lcd_en = 1, lcd_rs = 1
	GPIO_write(lcd_RS, 1);
	delay_us(50);
	GPIO_write(lcd_EN, 0);
	GPIO_write(lcd_RS, 1);             // lcd_en = 0, lcd_rs = 1
	delay_us(50);

	Send_4_bit((data & 0x0F) << 4);    // Send lower nibble
	GPIO_write(lcd_EN, 1);             // lcd_en = 1, lcd_rs = 1
	GPIO_write(lcd_RS, 1);
	delay_us(50);
	GPIO_write(lcd_EN, 0);
	GPIO_write(lcd_RS, 1);             // lcd_en = 0, lcd_rs = 1
	delay_us(50);
}



void LCD_String(volatile const char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)  // Send each character of string till the NULL
	{
		LCD_Char (str[i]);  // Call LCD data write
	}
}



void LCD_Init(volatile uint8_t lcd_rs, volatile uint8_t lcd_en, volatile uint8_t lcd_d4, volatile uint8_t lcd_d5, volatile uint8_t lcd_d6, volatile uint8_t lcd_d7)
{
	GPIO_mode(lcd_rs, OUT);
	GPIO_mode(lcd_en, OUT);
	GPIO_mode(lcd_d4, OUT);
	GPIO_mode(lcd_d5, OUT);
	GPIO_mode(lcd_d6, OUT);
	GPIO_mode(lcd_d7, OUT);

	lcd_RS = lcd_rs;
	lcd_EN = lcd_en;
	lcd_D4 = lcd_d4;
	lcd_D5 = lcd_d5;
	lcd_D6 = lcd_d6;
	lcd_D7 = lcd_d7;



	delay_ms(200);	      	// LCD Power ON Initialization time >15ms
	LCD_Command (0x02);    	// 4bit mode
	LCD_Command (0x28);	    // 4bit mode
	LCD_Command (0x0C);	    //Display ON Culcd_rsor OFF
	LCD_Command (0x06);   	// Auto Incremlcd_ent culcd_rsor
	LCD_Command (0x01);	    // Clear display
	LCD_Command (0x80);	    // Culcd_rsor at home position
}



void LCD_Cursor(volatile uint8_t row, volatile uint8_t column){
  if(row==0) LCD_Command(0x80 + column);
  else if(row==1) LCD_Command(0xc0 + column);
}



void LCD_Clear(){
  LCD_Command(0x01);
}






#endif /* LCD1602_H_ */
