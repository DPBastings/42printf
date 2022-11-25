/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:58:51 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 17:08:35 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

t_token	*ignore_flags(t_token *token)
{
	if (SPEC_IS_INTEGER(token))
	{
		if (HAS_FLAG(token, FLAG_LEFTALIGN))
			UNSET_FLAG(token, FLAG_ZEROPADDING);
	}
	if (token->specifier == SPEC_PTR)
		UNSET_FLAG(token, FLAG_ZEROPADDING);
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
