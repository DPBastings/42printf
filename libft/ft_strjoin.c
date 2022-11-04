/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 14:16:51 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/14 14:00:28 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(len * sizeof(char));
	if (string)
	{
		ft_strlcpy(string, s1, len);
		ft_strlcat(string, s2, len);
	}
	return (string);
}
