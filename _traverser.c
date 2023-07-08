#include "main.h"

/**
 * _traverser - takes in all necessary parameters to print a formatted string
 *
 * @format: the first va_arg
 * @list: list of all formated characters and their functions
 * @argu: the va_list variable
 *
 * Return: count of the printed characters
 */

int _traverser(const char *format, convert list[], va_list argu)
{
	int i, j, x, print_ch;

	print_ch = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; list[j].sym != NULL; j++)
			{
				if (format[i + 1] == list[j].sym[0])
				{
					x = list[j].f(argu);
					if (x == -1)
						return (-1);
					print_ch += x;
					break;
				}
			}
			if (list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					print_ch = print_ch + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			print_ch++;
		}
	}
	return (print_ch);
}
