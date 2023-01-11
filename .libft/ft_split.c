/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 13:16:23 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/24 16:50:17 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*cleanup(char **array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
		free(array[index++]);
	free(array);
	return (NULL);
}

static size_t	countwords(char const *s, char c)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (flag == 0)
				count++;
			flag = 1;
		}
		else
			flag = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(char const *s1, size_t n)
{
	char	*string;
	size_t	index;

	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
	string = malloc((n + 1) * sizeof(char));
	if (string)
	{
		index = 0;
		while (index < n)
		{
			string[index] = s1[index];
			index++;
		}
		string[index] = '\0';
	}
	return (string);
}

static int	isdelimiter(char c, char dl)
{
	return (c == dl || c == '\0');
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	arraysize;
	size_t	index;
	size_t	wordlen;

	arraysize = countwords(s, c);
	array = malloc((arraysize + 1) * sizeof(char *));
	if (array)
	{
		index = 0;
		wordlen = 0;
		while (index < arraysize)
		{
			wordlen += !isdelimiter(*s, c);
			if (isdelimiter(*s++, c) && wordlen > 0)
			{
				array[index] = ft_strndup(s - wordlen - 1, wordlen);
				if (!array[index++])
					return (cleanup(array, index));
				wordlen = 0;
			}
		}
		array[arraysize] = NULL;
	}
	return (array);
}
