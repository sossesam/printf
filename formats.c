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
	int length = 0;

	n = va_arg(unsign, unsigned int);

	while (n / expo > 9)
		expo *= 10;
	while (expo != 0)
	{
		length = length + _putchar(n / expo + '0');
		n = n % expo;
		expo = expo / 10;
	}
	return (length);
}


/**
 * _hex_str - converts the number from base 10 to hex
 * @n: number to be converted
 * @hex: base of 16 being passed
 * @alpha: Char 'A' to 'F' or 'a' to 'f'
 * Return: number of chars printed
 */
int _hex_str(unsigned int n, unsigned int hex, char alpha)
{
	unsigned int a = n % hex;
	unsigned int b = n / hex;
	char c;

	if (a > 10)
		c = (a - 10) + alpha;
	else
		c = a + '0';
	if (b == 0)
	{
		return (_putchar(c));
	}
	if (b < hex)
	{
		if (b > 10)
			return (_putchar(b - 10 + alpha) + _putchar(c));
		return (_putchar(b + '0') + _putchar(c));
	}
	return (_hex_str(b, hex, alpha) + _putchar(c));
}

/**
 * _hex_l - printing lower case hexa
 * @hexa: argument recieved
 * Return: no of char printed
 */
int _hex_l(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'a'));
}

/**
 * _hex_u - printing upper case hexa
 * @hexa: argument recieved
 * Return: no. of char printed
 */
int _hex_u(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'A'));
}

/**
 * _oct - function to print octal
 * @octo: list being passed
 * Return: updated count
 */
int _oct(va_list octo)
{
	int count = 0, i;
	int *arr;
	unsigned int n = va_arg(octo, unsigned int);
	unsigned int tmp = n;

	while (n / 8 != 0)
	{
		n /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		arr[i] = tmp % 8;
		tmp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}


/**
 * _rot13 - prints rot13 version
 * @rot: list being passed
 * Return: count of chars
 */
int _rot13(va_list rot)
{
	int a, count;
	char *s;

	a = count = 0;
	s = va_arg(rot, char *);

	if (s == NULL)
		return (-1);
	while (s[a] != '\0')
	{
		if ((s[a] >= 'a' && s[a] <= 'z') ||
		    (s[a] >= 'A' && s[a] <= 'Z'))
		{
			if ((s[a] >= 'n' && s[a] <= 'z') ||
			    (s[a] >= 'N' && s[a] <= 'Z'))
				count = count + _putchar(s[a] - 13);
			else
				count = count + _putchar(s[a] + 13);
		}
		else
			count = count + _putchar(s[a]);
		a++;
	}
	return (count);
}

int _backwards(va_list argu){
	int i = 0, j;
	char *s = va_arg(argu, char *);

	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}


int string_toupper(va_list argu)
{
    int n;
	char *str;
	str = va_arg(argu, char *);


    n = 0;
    while (*(str + n) != '\0')
    {
        if(*(str + n) >= 97 && *(str + n) <= 122)
        {
            _putchar(*(str + n));
        }else{
			_hex_u(*(str + n));
		}

        n++;
    }

   return (n);
}
