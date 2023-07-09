#include "main.h"

/**
 * _printf - print out the arguments to the standard output
 *
 * @format: the start of the endless arguments
 *
 * Return: An integer; the number of characters printed
 */

int _printf(const char *format, ...)
{
	int print_ch;

	convert list[] = {
		{"c", _char},
		{"s", _string},
		{"%", _percent},
		{"d", _decimal},
		{"i", _integer},
		{"b", _bin},
		{"u", _ui},
		{"x", _hex_l},
		{"X", _hex_u},
		{"o", _oct},
		{"R", _rot13},
		{"r", _backwards},
		{NULL, NULL}
	};

	va_list argu;

	if (format == NULL)
		return (-1);

	va_start(argu, format);

	print_ch = _traverser(format, list, argu);

	va_end(argu);
	return (print_ch);
}
