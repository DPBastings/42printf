/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:15:51 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/11 15:16:42 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	unsigned char	character;

	dst = (unsigned char *)b;
	character = (unsigned char) c;
	while (len--)
		*dst++ = character;
	return (b);
}
