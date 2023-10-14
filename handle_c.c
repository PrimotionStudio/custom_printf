#include "main.h"

/**
 * handle_char - Function to handle printing characters
 * @print: The holder of the arguments passed to the function
 * Return: The character to be printed
 */
int handle_char(va_list print)
{
	char c;

	c = va_arg(print, int);
	_putchar(c);
	return (0);
}
