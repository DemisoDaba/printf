/**
*_strlen - This function takes a character pointer as an argument.
*It initializes a variable len  to 0. it uses a for loop to to iterate
*over the characters in the string pointed to by the char pointer s.
*for each iteration it increments len by one.
*Finally the loop breaks when it meets a null character '\0'.
*The program then returns the current value of len.
*@s. A character pointer which points to the address of the string to be
*counted.
*This function is similar to strlen function defined in the string library
*This function is also a helper function in building our _printf function.
*As we will be using it to calculate the length of the string that we are
*to print. In fact we will need it for efficient string manipulation.
*Return: This function returns an interger which is the value for len.
*/

int _strlen(char *s)
{

	int len = 0;

	for(;*s != '\0';)
	{
	len++;
	s++;
	}
	return (len);
}

