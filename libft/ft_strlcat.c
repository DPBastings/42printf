/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:43:57 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/24 15:14:26 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	dstlen = 0;
	srclen = 0;
	while (dst[dstlen] && dstsize)
	{
		dstlen++;
		dstsize--;
	}
	while (src[srclen])
	{
		if (dstsize)
		{
			if (dstsize > 1)
				dst[dstlen + srclen] = src[srclen];
			else if (dstsize == 1)
				dst[dstlen + srclen] = '\0';
			dstsize--;
		}
		srclen++;
	}
	if (dstsize > 0)
		dst[dstlen + srclen] = '\0';
	return (dstlen + srclen);
}
