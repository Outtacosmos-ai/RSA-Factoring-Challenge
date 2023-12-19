#include "factor.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Factorizes a number
 * @buffer: Pointer to the address of the number
 *
 * Author: Thaoban Abdrasheed
 * Return: 0 on success
 */
int factorize(char *buffer)
{
	u_int32_t num, i;

	num = atoi(buffer);
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%d = %d * %d\n", num, num / i, i);
			break;
		}
	} return 0;
}
