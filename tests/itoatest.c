#include "./headers/misc.h"
#include <stdio.h>

int	main(void)
{
	char	buffer[64];
	int	ints[8] = {42, 1785, -1000, -2147483648, 2147483647, -594, 0, 26};
	int	index = 0;
	int	jindex;
	while (index < 8)
	{
		jindex = 0;
		while (jindex < 64)
			buffer[jindex++] = '\0';
		misc_itoa(ints[index++], buffer, "0123456789");
		printf("%s\n", buffer);
	}
	return (0);
}
