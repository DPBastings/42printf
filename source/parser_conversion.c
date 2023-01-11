/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_conversion.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 15:00:57 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 16:18:59 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "misc.h"
#include <stdlib.h>
#include <stdio.h>

static void	parse_flags(t_token *token, char const **format)
{
	while (ft_strchr(FLAGS, **format))
	{
		if (**format == '#')
			set_flag(token, FLAG_ALTERNATIVE);
		else if (**format == '0')
			set_flag(token, FLAG_ZEROPADDING);
		else if (**format == '-')
			set_flag(token, FLAG_LEFTALIGN);
		else if (**format == ' ')
			set_flag(token, FLAG_SPACE);
		else if (**format == '+')
			set_flag(token, FLAG_SIGNED);
		(*format)++;
	}
}

static void	parse_field_width(t_token *token, char const **format)
{
	token->field_width = misc_atoi(format);
}

static void	parse_precision(t_token *token, char const **format)
{
	token->precision = -1;
	if (**format == '.')
	{
		(*format)++;
		token->precision = misc_atoi(format);
	}
}

static int	parse_specifier(t_token *token, char const **format)
{
	char	*found;

	found = ft_strchr(SPECIFIERS, **format);
	if (found)
	{
		token->specifier = 1 + found - SPECIFIERS;
		(*format)++;
		return (1);
	}
	return (0);
}

t_token	*parse_conversion(char const **format)
{
	t_token		*token;
	char const	*start;

	(*format)++;
	start = *format;
	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	parse_flags(token, format);
	parse_field_width(token, format);
	parse_precision(token, format);
	if (!parse_specifier(token, format))
	{
		*format = start + 1;
		free(token);
		return (NULL);
	}
	ignore_flags(token);
	return (token);
}
