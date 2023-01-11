/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 12:23:09 by dbasting      #+#    #+#                 */
/*   Updated: 2022/12/06 10:26:07 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include "token.h"

static size_t	truncate(char const *str, t_token *token)
{
	size_t	len;

	len = ft_strlen(str);
	if (token->precision == -1)
		return (len);
	if (len > (size_t) token->precision)
		len = token->precision;
	return (len);
}

void	printstrconst(t_carriage *carriage, t_token *token, char *str)
{
	size_t	len;

	len = truncate(str, token);
	pad_left(carriage, token, len);
	carriage->print(carriage, str, len);
	pad_right(carriage, token, len);
}

void	printstr(t_carriage *carriage, t_token *token, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		printstrconst(carriage, token, "(null)");
	else
		printstrconst(carriage, token, str);
}
