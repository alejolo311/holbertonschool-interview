#include "palindrome.h"
/**
 * is_palindrome - check if number is a palindrome
 * @n: number
 * Return: 0 if not palindrome, 1 if is a palindrome
 */
int is_palindrome(unsigned long n)
{
	return (1 ? n == reverse(n) : 0);
}

/**
 * reverse - reverse a number
 * @n: number
 * Return: reversed
 */
unsigned long reverse(unsigned long n)
{
	unsigned long rev = 0;
	unsigned long cpy = n;

	while (cpy != 0)
	{
		rev = rev * 10;
		rev = rev + cpy % 10;
		cpy = cpy / 10;
	}
	return (rev);
}
