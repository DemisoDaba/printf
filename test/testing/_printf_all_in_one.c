#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to write
 *
 * Return: the number of characters written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }

    return (len);
}

/**
 * _puts - writes a string to stdout
 * @str: the string to write
 *
 * Return: the number of characters written
 */
int _puts(char *str)
{
    int len = _strlen(str);
    return write(1, str, len);
}

/**
 * _printf - produces output according to a format
 * @format: the format string
 * @...: the variable arguments
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    {
                        char *s = va_arg(args, char *);
                        count += write(1, s, _strlen(s));
                    }
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    {
                        int num = va_arg(args, int);
                        char str[12] = {0};
                        int i = 10, j = 0;

                        if (num == 0) {
                            str[j++] = '0';
                        }
                        else if (num < 0) {
                            str[j++] = '-';
                            num = -num;
                        }

                        while (num != 0) {
                            str[i--] = (num % 10) + '0';
                            num /= 10;
                        }
                        count += _puts(&str[i+1]);
                    }
                    break;       
		default:
                    count += write(1, format - 1, 2);
                    break;
		
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return (count);
}
