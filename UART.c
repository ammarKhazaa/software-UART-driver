#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Interface.h"
/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate)
{
   UCSRB = (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
   UCSRC = (1 << URSEL) | UART_u8NumberBits; // Use 8-bit character sizes

   UBRRH = (BAUD_PRESCALE >> 8); //25// Load upper 8-bits of the baud rate value into the high byte of the UBRR register
   UBRRL = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
 }

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data)
 {
    while(*Sent != '\0')
        {
    		UART_voidTransmit(*Sent++);
        }
 }
 
void UART_voidTransmit( u8 Data )
{
    /* Wait for empty transmit buffer */
    while(!( UCSRA & (1<<UDRE) ));

    /* Put data into buffer, sends the data */
    UDR = Data;
}
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data)
    {
        /* Wait for data to be received */
        while ( !(UCSRA & (1<<RXC)) );
        /* Get and return received data from buffer */
        return UDR;
    }