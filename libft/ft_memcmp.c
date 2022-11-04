/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 11:50:44 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/24 16:15:59 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*b1;
	const unsigned char	*b2;

	index = 0;
	b1 = (const unsigned char *)s1;
	b2 = (const unsigned char *)s2;
	while (index < n)
	{
		if ((unsigned char) b1[index] != (unsigned char) b2[index])
			break ;
		index++;
	}
	if (index < n)
		return ((unsigned char) b1[index] - (unsigned char) b2[index]);
	return (0);
}
