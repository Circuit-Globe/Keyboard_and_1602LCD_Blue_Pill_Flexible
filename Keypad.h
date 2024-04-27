/*
 * Keypad.h
 *
 *  Created on: Apr 27, 2024
 *      Author: dhara
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_




#include "STM32F103IO.h"


volatile uint8_t row0, row1, row2, row3, col0, col1, col2, col3;


void keypad_row_pin(volatile uint8_t ROW0, volatile uint8_t ROW1, volatile uint8_t ROW2, volatile uint8_t ROW3)
{
  GPIO_mode(ROW0, OUT);
	GPIO_mode(ROW1, OUT);
	GPIO_mode(ROW2, OUT);
	GPIO_mode(ROW3, OUT);

  row0 = ROW0;
  row1 = ROW1;
  row2 = ROW2;
  row3 = ROW3;
}



void keypad_column_pin(volatile uint8_t COL0, volatile uint8_t COL1, volatile uint8_t COL2, volatile uint8_t COL3)
{
  GPIO_mode(COL0, IN);
	GPIO_mode(COL1, IN);
	GPIO_mode(COL2, IN);
	GPIO_mode(COL3, IN);

  col0 = COL0;
  col1 = COL1;
  col2 = COL2;
  col3 = COL3;
}



void clear_row(){
  GPIO_write(row0, 0);
  GPIO_write(row1, 0);
  GPIO_write(row2, 0);
  GPIO_write(row3, 0);
}



volatile char keypad(){

	volatile char key;

	clear_row();           // Clear the pins connected to row
  GPIO_write(row0, 1);
       if(GPIO_read(col0)) key = '1';
  else if(GPIO_read(col1)) key = '2';
  else if(GPIO_read(col2)) key = '3';
  else if(GPIO_read(col3)) key = 'A';
  else key = 0;
  if(key) return key;


  clear_row();           // Clear the pins connected to row
  GPIO_write(row1, 1);
       if(GPIO_read(col0)) key = '4';
  else if(GPIO_read(col1)) key = '5';
  else if(GPIO_read(col2)) key = '6';
  else if(GPIO_read(col3)) key = 'B';
  else key = 0;
  if(key) return key;


  clear_row();           // Clear the pins connected to row
  GPIO_write(row2, 1);
       if(GPIO_read(col0)) key = '7';
  else if(GPIO_read(col1)) key = '8';
  else if(GPIO_read(col2)) key = '9';
  else if(GPIO_read(col3)) key = 'C';
  else key = 0;
  if(key) return key;


  clear_row();           // Clear the pins connected to row
  GPIO_write(row3, 1);
       if(GPIO_read(col0)) key = '*';
  else if(GPIO_read(col1)) key = '0';
  else if(GPIO_read(col2)) key = '#';
  else if(GPIO_read(col3)) key = 'D';
  else key = 0;
  if(key) return key;
}





#endif /* KEYPAD_H_ */
