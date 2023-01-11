/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 13:25:15 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/04 13:22:17 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*substring;

	index = ft_strlen(s);
	if (index <= (size_t) start)
		return (ft_strdup(""));
	if (index - (size_t) start < len)
		len = index - (size_t) start;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		substring[index] = s[index + (size_t) start];
		index++;
	}
	substring[index] = '\0';
	return (substring);
}
