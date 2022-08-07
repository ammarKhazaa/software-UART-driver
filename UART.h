#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*Comment:put your crystal value */
#define F_CPU_ 			4000000UL

/*Comment:choose baudrate value */
/*Range:UART_u8Bit(5~9) */
#define USART_BAUDRATE  9600
/*Comment:Choose number of bits */
/*Range:UART_u8SpeedMode,UART_u8MasterMode and UART_u8NormalMode */

#define BAUD_PRESCALE  UART_u8NormalMode//normal mode

/*Comment:Choose number of bits */
/*Range:UART_u8Bit(5~9) */
#define UART_u8NumberBits		UART_u8Bit9


#endif /* UART_CONFIG_H_ */