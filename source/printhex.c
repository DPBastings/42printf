/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printhex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 15:09:02 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/16 15:34:37 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include <stdarg.h>

void	printhex(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned int	number;
	char			*prefix;
	char			*string;

	number = va_arg(ap, unsigned int);
	prefix = get_prefix(token, number);
	if (token->specifier == SPEC_HEXUPP)
		string = misc_itostr(number, token, "0123456789ABCDEF");
	else
		string = misc_itostr(number, token, "0123456789abcdef");
	printnum(carriage, token, string, prefix);
}

void	printptr(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned long	pointer;
	char			*string;
	char			*prefix;

	pointer = (unsigned long) va_arg(ap, void *);
	prefix = misc_strdup("0x");
	string = misc_itostr(pointer, token, "0123456789abcdef");
	printnum(carriage, token, string, prefix);
}
