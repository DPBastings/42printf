/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 11:22:13 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/04 13:21:35 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	unsigned char		byte;

	mem = (const unsigned char *)s;
	byte = (unsigned char) c;
	while (n--)
	{
		if (*mem == byte)
			return ((char *)mem);
		mem++;
	}
	return (NULL);
}
