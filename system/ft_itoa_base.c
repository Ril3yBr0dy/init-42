#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	long 	val = (long)value;
	char	*b = "0123456789ABCDEF";
	char    *str = (char*)malloc(33);
	long 	power = 1;

	if (base < 2 || base > 16) return (NULL);
	int i = 0;
	if (val < 0)
	{
		val = -val;
		if (base == 10)
		{
			str[0] = '-';
			++i;
		}
	}
	while ((power * base) <= val)
		power *= base;

	while (power > 0)
	{
		str[i] = b[val / power];	
		val = val % power;
		power /= base;
		++i;
	}
    str[i] = '\0';
	return (str);
}

int main()
{
	for (int i = -256; i < 257; i++)
		printf("%s\n", ft_itoa_base(i, 10));
}

