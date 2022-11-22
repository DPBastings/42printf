/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:58:35 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 16:20:04 by dbasting      ########   odam.nl         */
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
		return ;
	if (token->flags & FLAG_ZEROPADDING)
		ft_memset(padding, '0', len);
	else
		ft_memset(padding, ' ', len);
	print(carriage, padding, len);
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
	if (!(token->flags & FLAG_LEFTALIGN))
		pad(carriage, token, len);
}

void	pad_right(t_carriage *carriage, t_token *token, size_t len)
{
	if (token->flags & FLAG_LEFTALIGN)
		pad(carriage, token, len);
}

char *get_prefix(t_token *token, long value)
{
	char	*prefix;
	size_t	index;

	prefix = ft_calloc(4, sizeof(char));
	if (prefix == NULL)
		return (NULL);
	index = 0;
	if (SPEC_IS_SIGNED(token))
	{
		if (value < 0)
			prefix[index++] = '-';
		else
		{
			if (HAS_FLAG(token, FLAG_SIGNED))
				prefix[index++] = '+';
			else if (HAS_FLAG(token, FLAG_SPACE))
				prefix[index++] = ' ';
		}
	}
	if (SPEC_IS_HEX(token) && HAS_FLAG(token, FLAG_ALTERNATIVE))
	{
		prefix[index++] = '0';
		if (token->specifier == SPEC_HEXLOW)
			prefix[index++] = 'x';
		else
			prefix[index++] = 'X';
	}
	return (prefix);
}
