/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:58:35 by dbasting      #+#    #+#                 */
/*   Updated: 2022/12/06 12:30:09 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "token.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	print_padding(t_carriage *carriage, t_token *token, size_t len)
{
	char	*padding;

	padding = malloc(len);
	if (padding == NULL)
	{
		carriage->printed = -1;
		return ;
	}
	if (has_flag(token, FLAG_ZEROPADDING))
		ft_memset(padding, '0', len);
	else
		ft_memset(padding, ' ', len);
	carriage->print(carriage, padding, len);
	free(padding);
}

static void	pad(t_carriage *carriage, t_token *token, size_t len)
{
	if (len < token->field_width)
		len = token->field_width - len;
	else
		len = 0;
	print_padding(carriage, token, len);
}

void	pad_left(t_carriage *carriage, t_token *token, size_t len)
{
	if (!(has_flag(token, FLAG_LEFTALIGN)))
		pad(carriage, token, len);
}

void	pad_right(t_carriage *carriage, t_token *token, size_t len)
{
	if (has_flag(token, FLAG_LEFTALIGN))
		pad(carriage, token, len);
}

char	*get_prefix(t_token *token, long value)
{
	char	*prefix;

	if (token->specifier == SPEC_DEC || token->specifier == SPEC_INT)
	{
		if (value < 0)
			prefix = ft_strdup("-");
		else if (has_flag(token, FLAG_SIGNED))
			prefix = ft_strdup("+");
		else if (has_flag(token, FLAG_SPACE))
			prefix = ft_strdup(" ");
		else
			prefix = ft_strdup("");
	}
	else if (has_flag(token, FLAG_ALTERNATIVE) && value != 0)
	{
		if (token->specifier == SPEC_HEXLOW)
			prefix = ft_strdup("0x");
		else if (token->specifier == SPEC_HEXUPP)
			prefix = ft_strdup("0X");
		else
			prefix = ft_strdup("");
	}
	else
		prefix = ft_strdup("");
	return (prefix);
}
