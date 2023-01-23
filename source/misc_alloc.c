/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc_alloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 12:07:17 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/23 12:07:19 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
