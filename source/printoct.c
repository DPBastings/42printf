/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printoct.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:20:33 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/16 15:34:48 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include <stdarg.h>

void	printoct(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned int	number;
	char			*prefix;
	char			*string;

	number = va_arg(ap, unsigned int);
	string = misc_itostr(number, token, "01234567");
	if (has_flag(token, FLAG_ALTERNATIVE)
		&& token->precision <= (int) misc_strlen(string))
		prefix = misc_strdup("0");
	else
		prefix = misc_strdup("");
	printnum(carriage, token, string, prefix);
}
