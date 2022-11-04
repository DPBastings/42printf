/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:22:39 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/24 10:56:05 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	neg;
	int	index;

	number = 0;
	neg = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		number *= 10;
		number += str[index] - '0';
		index++;
	}
	return (number * neg);
}
