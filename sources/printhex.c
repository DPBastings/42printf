/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printhex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 15:09:02 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 17:32:26 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include "../libft/libft.h"
#include <stdarg.h>

void	printhex(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned long	number;
	char			buffer[128];
	char			*prefix;

	number = (unsigned long) va_arg(ap, int);
	prefix = get_prefix(token, number);
	while (token->precision > 0)
		buffer[token->precision-- - 1] = '0';
	if (token->specifier == SPEC_HEXUPP)
		misc_itoa(number, buffer, "0123456789ABCDEF");
	else
		misc_itoa(number, buffer, "0123456789abcdef");
	printnum(carriage, token, buffer, prefix);
}

void	printptr(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned long	number;
	char			buffer[128];
	char 			*prefix;

	number = (unsigned long) va_arg(ap, void *);
	prefix = ft_strdup("0x");
	if (prefix == NULL)
		return ;
	misc_itoa(number, buffer, "0123456789abcdef");
	printnum(carriage, token, buffer, prefix);
}
