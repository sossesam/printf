#include "main.h"
#include <stdlib.h>

/**
 * _char - to print char formats
 *
 * @argu: the variadic variable for list of arguments
 *
 * Return: an integer; the count of characters printed
 */

int _char(va_list argu)
{
	_putchar(va_arg(argu, int));
	return (1);
}

/**
 * _string - to print string formats
 *
 * @argu: the variadic variable for list of arguments
 *
 * Return: an integer; the count of characters printed
 */

int _string(va_list argu)
{
	int i;
	char *str;

	str = va_arg(argu, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * _percent - to print % in formats
 *
 * @argu: the variadic variable for list of arguments
 *
 * Return: an integer; the count of characters printed
 */

int _percent(__attribute__((unused))va_list argu)
{
	_putchar('%');
	return (1);
}

/**
 * _decimal - to print decimal numbers in formats
 *
 * @argu: the variadic variable for list of arguments
 *
 * Return: an integer; the count of characters printed
 */

int _decimal(va_list list)
{
	int x, j ;
	unsigned int i = 0 , n;

	x = va_arg(list, int);
	j = 1;
	if (x < 0)
	{
		i += _putchar('-');
		n = x * -1;
	}
	else
		n = x;
	for (; (n / j) > 9; )
		j *= 10;
	for (; j != 0; )
	{
		i += _putchar('0' + (n / j));
		n %= j;
		j /= 10;
	}
	return (i);

}

int _integer(va_list argu)
{
	int _length;

	_length = _decimal(argu);
	return (_length);
}

int _bin(va_list bin)
{
	int count = 0, i;
	int *arr;
	unsigned int n = va_arg(bin, unsigned int);
	unsigned int tmp = n;

	while (n / 2 != 0)
	{
		n /= 2;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	if (arr == NULL)
	{
		free(arr);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		arr[i] = tmp % 2;
		tmp /= 2;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}


/**
 * _ui - unsigned int print to stdout
 * @unsign: list being passed
 * Return: char count
 */
int _ui(va_list unsign)
{
	unsigned int n;
	int expo = 1;
	int len = 0;

	n = va_arg(unsign, unsigned int);

	while (n / expo > 9)
		expo *= 10;
	while (expo != 0)
	{
		len = len + _putchar(n / expo + '0');
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}
