#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct convertion - defining symbols and structure
 *
 * @sym: operator
 * @f: function associated
 */

struct convertion
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convertion convert;

int _putchar(char c);
int _printf(const char *format, ...);
int _traverser(const char *format, convert list[], va_list argu);
int _char(va_list);
int _string(va_list);
int _percent(va_list);
int _integer(va_list);
int _decimal(va_list);
int _bin(va_list argu);
int _ui(va_list unsign);
int _hex_l(va_list hexa);
int _hex_str(unsigned int n, unsigned int hex, char alpha);
int _hex_u(va_list hexa);
int _oct(va_list octo);
int _rot13(va_list rot);
int _backwards(va_list argu);
int string_toupper(va_list argu);

#endif
