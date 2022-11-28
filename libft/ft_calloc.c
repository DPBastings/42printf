/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 12:31:40 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 14:46:43 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;

	memory = malloc(count * size);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}
