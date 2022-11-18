/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:58:51 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 17:29:07 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

t_token *ignore_flags(t_token *token)
{
	if (ft_strchr(SPECIFIERS_INT, token->specifier))
	{
		if (token->precision != 1)
		{
			token->flags |= FLAG_ZEROPADDING;
			token->flags &= ~FLAG_LEFTALIGN;
			token->field_width = 0;
		}
	}
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
