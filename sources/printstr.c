/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 12:23:09 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 18:22:02 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "token.h"
#include "../libft/libft.h"
#include <stdio.h>

static size_t	truncate(char *str, t_token *token)
{
	size_t	len;

	len = ft_strlen(str);
	if (token->precision == -1)
		return (len);
	if (len > (size_t) token->precision)
		len = token->precision;
	return (len);
}

void	printstr(t_carriage *carriage, t_token *token, va_list ap)
{
	char	*str;
	size_t	len;

	str = va_arg(ap, char *);
	len = truncate(str, token);
	pad_left(carriage, token, len);
	print(carriage, str, len);
	pad_right(carriage, token, len);
}
