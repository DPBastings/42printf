/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:38:13 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/04 13:18:16 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{	
	char	character;

	character = (char) c;
	while (*s)
	{
		if (*s == character)
			return ((char *)s);
		s++;
	}
	if (character == '\0')
		return ((char *)s);
	return (NULL);
}
