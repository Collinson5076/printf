#include "main.h"

/**
 * print_n - Entry point. Print number
 * @n: Variable va_list
 *
 * Return: count 
 */
int print_n(va_list n)
{

	long int num;
	int count = 0;
	int aux_variable, base;

	num = va_arg(n, int);

	if (num < 0)
	{
		num *= -1;
		_putchar(45);
		count++;
	}
	if (num >= 0 && num <= 9)
	{
		_putchar(num + 48);
		count++;
	}
	if (num > 9)
	{
		base = 10;

		while (num / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			aux_variable = num / base;
			num = num % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			count++;
		}
	}
	return (count);
}
