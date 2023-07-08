#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int x,y;
 x =_printf("%u", -1024);
 y = printf("%u", -1024);

printf("myprintf = %d, printf = %d \n", x, y);
	return (0);
}
