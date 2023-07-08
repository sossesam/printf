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

#endif
