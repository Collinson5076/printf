#include "main.h"

/**
* _printf - function to produce output according to a format
* @format: a list of types of arguments passed to the function.
*
* Return: number of characters printed excluding null byte
*/
int _printf(const char *format, ...)
{
	va_list ch;
	int count = 0;
	int i = 0;
	char *st;

	if (!format)
		return (-1);
	
	va_start(ch, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(ch, int));
					break;
				case 's':
					st = va_arg(ch, char *);
					if (!st)
						st = "(null)";
					while (*st)
						count += _putchar(*st++);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(ch);
	return (count);
}

