/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:46:13 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 14:29:40 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"
#include "../libft/libft.h"

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

void	ft_strrev(char *str)
{
	char	*end;
	char	storage;

	end = str + ft_strlen(str) - 1;
	while (str < end)
	{
		storage = *str;
		*str++ = *end;
		*end-- = storage;
	}
}

void	misc_itoa(unsigned long number, char *array, char const *digits)
{
	size_t	radix;
	size_t	index;

	radix = ft_strlen(digits);
	index = 0;
	if (number == 0)
		array[index++] = digits[0];
	while (number)
	{
		array[index++] = digits[number % radix];
		number /= radix;
	}
	array[index] = '\0';
	ft_strrev(array);
}

int	misc_atoi(char const **str)
{
	int	number;
	
	number = 0;
	while (ft_isspace(**str))
		(*str)++;
	while (ft_isdigit(**str))
	{
		number *= 10;
		number += **str - '0';
		(*str)++;
	}
	return (number);
}
