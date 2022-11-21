/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:58:35 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 14:29:38 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "token.h"
#include "../libft/libft.h"
#include <stdlib.h>

static void	print_padding(t_carriage *carriage, t_token *token, size_t len)
{
	char	*padding;

	padding = malloc(len);
	if (padding == NULL)
		return ;
	if (token->flags & FLAG_ZEROPADDING)
		ft_memset(token, '0', len);
	else
		ft_memset(token, ' ', len);
	print(carriage, padding, len);
	free(padding);
}

//kan wellicht ook zonder malloc

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
