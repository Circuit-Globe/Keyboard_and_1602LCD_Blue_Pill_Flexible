/*
 * STM32F103IO.h
 *
 *  Created on: Apr 27, 2024
 *      Author: dhara
 */

#ifndef STM32F103IO_H_
#define STM32F103IO_H_




#define       GPIOA_IN             *porta_input_reg
#define       GPIOA_OUT            *porta_output_reg
#define       GPIOB_IN             *portb_input_reg
#define       GPIOB_OUT            *portb_output_reg
#define       GPIOC_IN             *portc_input_reg
#define       GPIOC_OUT            *portc_output_reg

#define       RCC_base_add         0x40021000
#define       APB2_offset          0x18
#define       PORTA_base_add       0x40010800
#define       PORTB_base_add       0x40010C00
#define       PORTC_base_add       0x40011000
#define       GPIO_CRL_offset      0x00
#define       GPIO_CRH_offset      0x04
#define       GPIO_ODR_offset      0x0C
#define       GPIO_IDR_offset      0x08

#define       input_mode           8
#define       output_mode          2
#define       clear                15
#define       IN                   0
#define       OUT                  1

#define       PA0                  0
#define       PA1                  1
#define       PA2                  2
#define       PA3                  3
#define       PA4                  4
#define       PA5                  5
#define       PA6                  6
#define       PA7                  7
#define       PA8                  8
#define       PA9                  9
#define       PA10                 10
#define       PA11                 11
#define       PA12                 12
#define       PA13                 13
#define       PA14                 14
#define       PA15                 15

#define       PB0                  16
#define       PB1                  17
#define       PB2                  18
#define       PB3                  19
#define       PB4                  20
#define       PB5                  21
#define       PB6                  22
#define       PB7                  23
#define       PB8                  24
#define       PB9                  25
#define       PB10                 26
#define       PB11                 27
#define       PB12                 28
#define       PB13                 29
#define       PB14                 30
#define       PB15                 31

#define       PC0                  32
#define       PC1                  33
#define       PC2                  34
#define       PC3                  35
#define       PC4                  36
#define       PC5                  37
#define       PC6                  38
#define       PC7                  39
#define       PC8                  40
#define       PC9                  41
#define       PC10                 42
#define       PC11                 43
#define       PC12                 44
#define       PC13                 45
#define       PC14                 46
#define       PC15                 47




volatile uint32_t *clock_reg    =   (uint32_t*) (RCC_base_add + APB2_offset);

volatile uint32_t *porta_mode_reg_low     =    (uint32_t*) (PORTA_base_add + GPIO_CRL_offset);
volatile uint32_t *porta_mode_reg_high    =    (uint32_t*) (PORTA_base_add + GPIO_CRH_offset);
volatile uint32_t *porta_input_reg        =    (uint32_t*) (PORTA_base_add + GPIO_IDR_offset);
volatile uint32_t *porta_output_reg       =    (uint32_t*) (PORTA_base_add + GPIO_ODR_offset);

volatile uint32_t *portb_mode_reg_low     =    (uint32_t*) (PORTB_base_add + GPIO_CRL_offset);
volatile uint32_t *portb_mode_reg_high    =    (uint32_t*) (PORTB_base_add + GPIO_CRH_offset);
volatile uint32_t *portb_input_reg        =    (uint32_t*) (PORTB_base_add + GPIO_IDR_offset);
volatile uint32_t *portb_output_reg       =    (uint32_t*) (PORTB_base_add + GPIO_ODR_offset);

volatile uint32_t *portc_mode_reg_low     =    (uint32_t*) (PORTC_base_add + GPIO_CRL_offset);
volatile uint32_t *portc_mode_reg_high    =    (uint32_t*) (PORTC_base_add + GPIO_CRH_offset);
volatile uint32_t *portc_input_reg        =    (uint32_t*) (PORTC_base_add + GPIO_IDR_offset);
volatile uint32_t *portc_output_reg       =    (uint32_t*) (PORTC_base_add + GPIO_ODR_offset);





void GPIO_mode(volatile uint8_t pin_number, volatile uint8_t mode)
{
/*---------------------------------------------------------------------------------------------------------*/
/*                                           PORTA pin configuration                                       */
/*---------------------------------------------------------------------------------------------------------*/

    if((pin_number >= 0) && (pin_number <= 7)){
      /* Enable PORTA */
      *clock_reg |=  (1 << 2);
      /* Clear the respective pin mode & config bits */
      *porta_mode_reg_low    &=     ~(clear << (4*pin_number));

           if(mode == 1) *porta_mode_reg_low |= (output_mode << (4*pin_number));   /* Mode == 1 means OUTPUT */
      else if(mode == 0) *porta_mode_reg_low |= (input_mode << (4*pin_number));    /* Mode == 0 means INPUT */
    }


    else if((pin_number >= 8) && (pin_number <= 15)){
      /* Enable PORTA */
      *clock_reg |=  (1 << 2);
      /* for clear the respective pin mode & config bits */
      *porta_mode_reg_high &= ~(clear << (4*(pin_number - 8)));

           if(mode == 1) *porta_mode_reg_high |= (output_mode << (4*(pin_number - 8)));   /* Mode == 1 means OUTPUT */
      else if(mode == 0) *porta_mode_reg_high |= (input_mode << (4*(pin_number - 8)));    /* Mode == 0 means INPUT */
    }



/*---------------------------------------------------------------------------------------------------------*/
/*                                           PORTB pin configuration                                       */
/*---------------------------------------------------------------------------------------------------------*/

    else if((pin_number >= 16) && (pin_number <= 23)){
      /* Enable PORTB */
      *clock_reg |=  (1 << 3);
      /* Clear the respective pin mode & config bits */
      *portb_mode_reg_low    &=     ~(clear << (4*(pin_number - 16)));

           if(mode == 1) *portb_mode_reg_low |= (output_mode << (4*(pin_number - 16)));   /* Mode == 1 means OUTPUT */
      else if(mode == 0) *portb_mode_reg_low |= (input_mode << (4*(pin_number - 16)));    /* Mode == 0 means INPUT */
    }


    else if((pin_number >= 24) && (pin_number <= 31)){
      /* Enable PORTB */
      *clock_reg |=  (1 << 3);
      /* for clear the respective pin mode & config bits */
      *portb_mode_reg_high &= ~(clear << (4*(pin_number - 24)));

           if(mode == 1) *portb_mode_reg_high |= (output_mode << (4*(pin_number - 24)));   /* Mode == 1 means OUTPUT */
      else if(mode == 0) *portb_mode_reg_high |= (input_mode << (4*(pin_number - 24)));    /* Mode == 0 means INPUT */
    }



/*---------------------------------------------------------------------------------------------------------*/
/*                                           PORTC pin configuration                                       */
/*---------------------------------------------------------------------------------------------------------*/

    else if((pin_number >= 32) && (pin_number <= 39)){
      /* Enable PORTC */
      *clock_reg |=  (1 << 4);
      /* Clear the respective pin mode & config bits */
      *portc_mode_reg_low    &=     ~(clear << (4*(pin_number - 32)));

           if(mode == 1) *portc_mode_reg_low |= (output_mode << (4*(pin_number - 32)));   /* Mode == 1 means OUTPUT */
      else if(mode == 0) *portc_mode_reg_low |= (input_mode << (4*(pin_number - 32)));    /* Mode == 0 means INPUT */
    }


    else if((pin_number >= 40) && (pin_number <= 47)){
      /* Enable PORTC */
      *clock_reg |=  (1 << 4);
      /* for clear the respective pin mode & config bits */
      *portc_mode_reg_high &= ~(clear << (4*(pin_number - 40)));

           if(mode == 1) *portc_mode_reg_high |= (output_mode << (4*(pin_number - 40)));   /* Mode == 1 means OUTPUT */
      else if(mode == 0) *portc_mode_reg_high |= (input_mode << (4*(pin_number - 40)));    /* Mode == 0 means INPUT */
    }

}



void GPIO_write(volatile uint8_t pin_number, volatile uint8_t pin_state)
{
  if((pin_number >= 0) && (pin_number <= 15)){
         if(pin_state == 1) *porta_output_reg |=  (1 << pin_number);
    else if(pin_state == 0) *porta_output_reg &= ~(1 << pin_number);
  }

  else if((pin_number >= 16) && (pin_number <= 31)){
         if(pin_state == 1) *portb_output_reg |=  (1 << (pin_number - 16));
    else if(pin_state == 0) *portb_output_reg &= ~(1 << (pin_number - 16));
  }

  if((pin_number >= 32) && (pin_number <= 47)){
         if(pin_state == 1) *portc_output_reg |=  (1 << (pin_number - 32));
    else if(pin_state == 0) *portc_output_reg &= ~(1 << (pin_number - 32));
  }
}



volatile uint32_t GPIO_read(volatile uint32_t pin_number){
       if((pin_number >=  0) && (pin_number <= 15)) return ((*porta_input_reg >> pin_number) & 1);
  else if((pin_number >= 16) && (pin_number <= 31)) return ((*portb_input_reg >> (pin_number - 16)) & 1);
  else if((pin_number >= 32) && (pin_number <= 47)) return ((*portc_input_reg >> (pin_number - 32)) & 1);
}



/* Mili second delay */
void delay_ms(volatile uint16_t time){
	volatile uint16_t x, y;
	for(x=0; x<time; x++)
	for(y=0; y<235; y++);
}


/* Micro second delay */
void delay_us(volatile uint16_t time){
	for(volatile uint16_t x=0; x<time; x++);
}





#endif /* STM32F103IO_H_ */
