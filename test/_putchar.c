#include "main.h"

/**
*_putchar - This functions takes a char c as an argument
*and uses the write function from the unistd library to
*print the character held by the variable c to the standard output.
*The function returns an interger which is the number of character
*printed which will always be one as the function does not print
*more than a character. And
*it returns -1 when an error is encountered
*We need this function as a helper function for our _printf function
*To print a single character to the standard output like when dealing
*with the case of %c.
*@c:Is the character to be printed or the variable which stores the
*character to be printed.
*Return: Returns an interger 1 on success and -1 if error is encountered
*/

int _putchar(char c)
	{
		return (write(1, &c, 1));
	}

