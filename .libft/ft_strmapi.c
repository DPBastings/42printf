/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:35:41 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/24 11:47:39 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	len;
	size_t	index;

	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	string = malloc((len + 1) * sizeof(char));
	if (string)
	{
		index = 0;
		while (index < len)
		{
			string[index] = f((unsigned int) index, s[index]);
			index++;
		}
		string[index] = '\0';
	}
	return (string);
}
