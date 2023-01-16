#include "misc.h"
#include <stdlib.h>

void	*misc_calloc(size_t n, size_t size)
{
	unsigned char	*memory;

	memory = malloc(n * size);
	if (memory == NULL)
		return (NULL);
	misc_memset(memory, '\0', n * size);
	return (memory);
}
