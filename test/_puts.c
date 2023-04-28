#include "main.h"

/**
*_puts - This function takes a char pointer str which points to the
*memory address of a string that we want to print to the standard output
*It then initializes the value of len to the value of _strlen function when
*the pointer str is passed to it as an argument. The program then uses the
*write function from the unistd library to return the the
*string str, len(which is the length of the string str) and 1 when
*error is ecountered
*@str: The string to be printed and counted.
*Return: The the length of the string str on success or 1 when it
*encountered an error.
*/

int _puts(char *str)
{
	int len = _strlen(str);

	return (write(1, str, len));
}

