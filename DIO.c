#define IN 0
#define OUT 1
#define LOW 0
#define HIGH 1

#include "DIO_Private.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO-utilites.h"
/*********************************************************************/
u8* const DIO_u8ArrPORT[4]={&PORTA,&PORTB,&PORTC,&PORTD};
u8* const DIO_u8ArrDDR[4]= {&DDRA,&DDRB,&DDRC,&DDRD};
u8* const DIO_u8ArrPIN[4]= {&PINA,&PINB,&PINC,&PIND};

/*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * direction: is an input argument that describes the data direction on a specific pin, IN or OUT
 */
 void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction)
{
	DDRA=DIO_u8PORTADIR;//ELY ANA BSHAER 3LEH 5LEH BL2IMH DEH
	DDRB=DIO_u8PORTBDIR;
	DDRC=DIO_u8PORTCDIR;
	DDRD=DIO_u8PORTDDIR;

	/*Comment!:karnouf map  */
	PORTA=(DIO_u8PORTAVAL & DIO_u8PORTADIR ) | (PORTA & (~DIO_u8PORTADIR));
	PORTB=(DIO_u8PORTBVAL & DIO_u8PORTBDIR ) | (PORTB & (~DIO_u8PORTBDIR));
	PORTC=(DIO_u8PORTCVAL & DIO_u8PORTCDIR ) | (PORTC & (~DIO_u8PORTCDIR));
	PORTD=(DIO_u8PORTDVAL & DIO_u8PORTDDIR ) | (PORTD & (~DIO_u8PORTDDIR));

}
 
 /*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * value: is an input argument that describes the value on a specific pin, LOW or HIGH
 */
 void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value)
{
		u8 Local_u8Status,Local_u8Port,Local_u8Pin;
		if(Copy_u8PinIdx < DIO_u8NumberAllPins)
		{
			Local_u8Port=Copy_u8PinIdx / DIO_u8NumberOfPin;
			Local_u8Pin= Copy_u8PinIdx % DIO_u8NumberOfPin;
			if(Copy_u8PinToVal==DIO_u8LOW)
			{
				Clr_Bit(*DIO_u8ArrPORT[Local_u8Port],Local_u8Pin);
			}
			else
			{
				Set_Bit(*DIO_u8ArrPORT[Local_u8Port],Local_u8Pin);
			}
			Local_u8Status=Ok;
		}
		else
		{
			Local_u8Status=Error;
		}
		return Local_u8Status;

}

/*
 * pinNumber: is an input argument that describes pin number in each port, 0, 1, 2, ... etc.
 * port: is an input argument that describes port character, 'A', 'B', ... etc.
 * value: is an output argument that describes the value on a specific pin, LOW or HIGH
 */
 void DIO_read(uint8_t pinNumber, uint8_t port, uint8_t *value)
{
	u8 Local_u8Status;

	if(Copy_u8PortIdx < DIO_u8NumberOfPort)
	{
		*Copy_u8PtrToVal=*DIO_u8ArrPIN[Copy_u8PortIdx];
		Local_u8Status=Ok;
	}
	else
	{
		Local_u8Status=Error;
	}
	return Local_u8Status;
}