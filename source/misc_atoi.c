/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:46:13 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/16 15:31:04 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"
#include "token.h"
#include <stdlib.h>

static void	misc_strrev(char *str)
{
	char	*end;
	char	storage;

	end = str + misc_strlen(str) - 1;
	while (str < end)
	{
		storage = *str;
		*str++ = *end;
		*end-- = storage;
	}
}

int	misc_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static size_t	misc_itoa(unsigned long number, char *array, char const *digits)
{
	size_t	radix;
	size_t	index;

	radix = misc_strlen(digits);
	index = 0;
	if (number == 0)
		array[index++] = digits[0];
	while (number)
	{
		array[index++] = digits[number % radix];
		number /= radix;
	}
	array[index] = '\0';
	misc_strrev(array);
	return (index);
}

char	*misc_itostr(unsigned long number, t_token *token, char const *digits)
{
	char	*string;
	char	buffer[32];
	size_t	len;
	size_t	leading;

	if (!(number == 0 && token->precision == 0))
		len = misc_itoa(number, buffer, digits);
	else
		len = 0;
	if (token->precision != -1 && (size_t) token->precision > len)
		leading = token->precision - len;
	else
		leading = 0;
	string = misc_calloc((leading + len + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	misc_memset(string, '0', leading);
	misc_strlcat(string, buffer, leading + len + 1);
	return (string);
}

int	misc_atoi(char const **str)
{
	int	number;

	number = 0;
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	while (misc_isdigit(**str))
	{
		number *= 10;
		number += **str - '0';
		(*str)++;
	}
	return (number);
}
