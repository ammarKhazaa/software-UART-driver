
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UCSRB_u8Address	(0x2A)
#define UCSRC_u8Address	(0x40)
#define UBRRH_u8Address	(0x20)
#define UBRRL_u8Address	(0x29)
#define UCSRA_u8Address	(0x2B)
#define UDR_u8Address	(0x2C)



#define UDR		(*(volatile u8 *) UDR_u8Address)

#define UCSRB	(*(volatile u8 *) UCSRB_u8Address)
#define RXEN	4
#define TXEN	3
/*
UCSZ2 UCSZ1 UCSZ0 Character Size
0 		0 	 0 			5-bit
0 		0 	 1 			6-bit
0 		1 	 0 			7-bit
0 		1 	 1 			8-bit
1 		0 	 0 			Reserved
1 		0 	 1 			Reserved
1 		1 	 0 			Reserved
1 		1 	 1 			9-bit
*/
#define UCSRC		(*(volatile u8 *) UCSRC_u8Address)
#define URSEL	7
#define UCSZ0	1
#define UCSZ1	2
#define UCSZ2	3
#define USBS	3

#define UART_u8StopBit1	()
#define	UART_u8Bit5		(0<<UCSZ0)|(0<<UCSZ1)|(0<<UCSZ2)
#define	UART_u8Bit6		(0<<UCSZ0)|(0<<UCSZ1)|(1<<UCSZ2)
#define	UART_u8Bit7		(0<<UCSZ0)|(1<<UCSZ1)|(0<<UCSZ2)
#define	UART_u8Bit8		(0<<UCSZ0)|(1<<UCSZ1)|(1<<UCSZ2)
#define	UART_u8Bit9		(1<<UCSZ0)|(1<<UCSZ1)|(1<<UCSZ2)

#define UBRRL		(*(volatile u8 *) UBRRL_u8Address)
#define UBRRH		(*(volatile u8 *) UBRRH_u8Address)

#define UCSRA		(*(volatile u8 *) UCSRA_u8Address)
#define UDRE	5
#define RXC		7


#define UART_u8NormalMode (((F_CPU_ / (USART_BAUDRATE * 16UL))) - 1)
#define UART_u8SpeedMode  (((F_CPU_ / (USART_BAUDRATE * 8UL ))) - 1)
#define UART_u8MasterMode (((F_CPU_ / (USART_BAUDRATE * 2UL))) - 1)

#endif /* UART_PRIVATE_H_ */




