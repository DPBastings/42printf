/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:58:51 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 12:27:40 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "misc.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

t_token	*ignore_flags(t_token *token)
{
	if (has_flag(token, FLAG_LEFTALIGN))
		unset_flag(token, FLAG_ZEROPADDING);
	if (is_int_conversion(token) && token->precision != -1)
		unset_flag(token, FLAG_ZEROPADDING);
	else if (token->specifier == SPEC_PTR)
		unset_flag(token, FLAG_ZEROPADDING);
	return (token);
}

t_token	*parse_literal(char const **format)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->flags = **format;
	(*format)++;
	return (new);
}

t_token	*parser(char const **format)
{
	t_token	*new;

	if (**format == '%')
	{
		new = parse_conversion(format);
		if (new == NULL)
			return (NULL);
	}
	else
	{
		new = parse_literal(format);
		if (new == NULL)
			return (NULL);
	}
	return (new);
}
