/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:23:18 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/24 15:19:33 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && s1[index] && s2[index])
	{
		if ((unsigned char)(s1[index]) != (unsigned char)(s2[index]))
			break ;
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char) s1[index] - (unsigned char) s2[index]);
}
