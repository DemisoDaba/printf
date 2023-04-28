#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format string
 * @...: the variable arguments
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;
	int count = 0;
	char binary[33];
	unsigned int num;
	va_list printf;
	va_start(printf, format);

	for (; *format != '\0'; )
	{
	if (*format == '%')
	{
	format++;

	switch (*format)
	{

	case 'c':
	count = count + _putchar(va_arg(printf, int));
	break;

	case 's':
	{
	count += _puts(va_arg(printf, char*));
	}
	break;

	case '%':
	count += _putchar('%');
	break;

	case 'd':
	case 'i':
	{
	int num = va_arg(printf, int);
	char str[12] = {0};
	int i = 10, j = 0;

	if (num == 0)
	{
	str[j++] = '0';
	}
	else if (num < 0)
	{
	str[j++] = '-';
	num = -1 * num;
	}
	while (num != 0)
	{
	str[i--] = (num % 10) + '0';
	num = num / 10;
	}
	count = count + _puts(&str[i + 1]);
	}
	break;
	case 'b':
	{
	num = va_arg(printf, unsigned int);
	binary[33] = 0;
	i = 31;
	do {
	binary[i--] = (num % 2) + '0';
	num = num / 2;
	} while (num != 0);
	count = count + _puts(&binary[i + 1]);
	}
	break;
	default:
	count = count + write(1, format - 1, 2);
	break;
	}
	}
	else
	{
	count = count + _putchar(*format);
	}
	format++;
	}
	va_end(printf);
	return (count);
}
