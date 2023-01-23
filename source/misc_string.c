/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc_string.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 12:08:03 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/23 12:08:04 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"
#include <stddef.h>
#include <stdlib.h>

size_t	misc_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*misc_strchr(char const *str, int c)
{
	char	character;

	character = c;
	while (*str)
	{
		if (*str == character)
			return ((char *)str);
		str++;
	}
	if (character == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	misc_strlcat(char *dst, char const *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	dstlen = 0;
	srclen = 0;
	while (dst[dstlen] && size)
	{
		dstlen++;
		size--;
	}
	while (src[srclen])
	{
		if (size)
		{
			if (size > 1)
				dst[dstlen + srclen] = src[srclen];
			else
				dst[dstlen + srclen] = '\0';
			size--;
		}
		srclen++;
	}
	if (size > 0)
		dst[dstlen + srclen] = '\0';
	return (dstlen + srclen);
}

void	*misc_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;

	dst = b;
	while (len)
	{
		*dst++ = (unsigned char) c;
		len--;
	}
	return (b);
}

char	*misc_strdup(char const *str)
{
	char	*dup;
	size_t	size;

	size = misc_strlen(str) + 1;
	dup = malloc(sizeof(char) * size);
	if (dup == NULL)
		return (NULL);
	while (size--)
		dup[size] = str[size];
	return (dup);
}
