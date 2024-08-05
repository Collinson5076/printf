#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: format string containing the characters and the specifiers
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')

			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind); /* Buffer is full, let's print it */
			printed_chars++
		}
		else
		{
			print_buffer(buffer, &buff_ind); /* Print current buffer before processing the format specifier */
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1); /* Error occurred, return -1 */
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind); /* Print any remaining characters in buffer */

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if there are any
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind); /* Only write if there's something to write */

		*buff_ind = 0; /* Reset buffer index */
}
