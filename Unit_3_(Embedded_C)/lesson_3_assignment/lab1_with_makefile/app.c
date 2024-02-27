// Alfred Fayez
#include "UART.h"

unsigned char string_buffer[100] = "Learn-in-depth: Alfred Fayez";
unsigned char const string_buffer2[100] = "Learn-in-depth: Alfred Fayez";
void main()
{
	UART_Send_string (string_buffer);
}