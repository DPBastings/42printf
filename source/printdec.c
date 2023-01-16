/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printdec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:12:09 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/16 15:34:23 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

void	printnum(t_carriage *carriage, t_token *token, char *str, char *prfx)
{
	size_t	string_len;
	size_t	prefix_len;

	string_len = misc_strlen(str);
	prefix_len = misc_strlen(prfx);
	if (has_flag(token, FLAG_ZEROPADDING))
		carriage->print(carriage, prfx, prefix_len);
	pad_left(carriage, token, prefix_len + string_len);
	if (!(has_flag(token, FLAG_ZEROPADDING)))
		carriage->print(carriage, prfx, prefix_len);
	carriage->print(carriage, str, string_len);
	pad_right(carriage, token, prefix_len + string_len);
	free(prfx);
	free(str);
}

void	printdec(t_carriage *carriage, t_token *token, va_list ap)
{
	int		number;
	char	*prefix;
	char	*string;

	number = va_arg(ap, int);
	prefix = get_prefix(token, number);
	if (number == -2147483648)
		string = misc_itostr(2147483648, token, "0123456789");
	else
	{
		if (number < 0)
			number *= -1;
		string = misc_itostr(number, token, "0123456789");
	}
	printnum(carriage, token, string, prefix);
}

void	printuns(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned int	number;
	char			*prefix;
	char			*string;

	number = va_arg(ap, unsigned int);
	prefix = get_prefix(token, number);
	string = misc_itostr(number, token, "0123456789");
	printnum(carriage, token, string, prefix);
}
