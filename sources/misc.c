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
#include "token.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static void	ft_strrev(char *str)
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

char	*misc_itostr(unsigned long number, t_token *token, char const *digits)
{
	char	*string;
	char	buffer[64];
	size_t	len;
	size_t	leading;

	if (token->precision == 0)
		return (ft_strdup(""));
	len = misc_itoa(number, buffer, digits);
	if (token->precision != -1 && (size_t) token->precision > len)
		leading = token->precision - len;
	else
		leading = 0;
	string = ft_calloc((leading + len + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_memset(string, '0', leading);
	ft_strlcat(string, buffer, leading + len + 1);
	return (string);
}

size_t	misc_itoa(unsigned long number, char *array, char const *digits)
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
	return (index);
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
