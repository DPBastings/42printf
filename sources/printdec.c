/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printdec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:12:09 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 14:51:15 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

void	printnum(t_carriage *carriage, t_token *token, char *buffer, char *prefix)
{
	size_t	buffer_len;
	size_t	prefix_len;
	
	buffer_len = ft_strlen(buffer);
	prefix_len = ft_strlen(prefix);
	if (HAS_FLAG(token, FLAG_ZEROPADDING))
		print(carriage, prefix, prefix_len);
	pad_left(carriage, token, buffer_len + prefix_len);
	if (!(HAS_FLAG(token, FLAG_ZEROPADDING)))
		print(carriage, prefix, prefix_len);
	print(carriage, buffer, buffer_len);
	pad_right(carriage, token, buffer_len + prefix_len);
	free(prefix);
}

static void	fill_precision(char *buffer, t_token *token)
{
	while (token->precision > 0)
		buffer[token->precision-- - 1] = '0';
}

void	printdec(t_carriage *carriage, t_token *token, va_list ap)
{
	long	number;
	char	buffer[128];
	char	*prefix;

	number = (long) va_arg(ap, int);
	prefix = get_prefix(token, number);
	if (number < 0)
		number *= -1;
	fill_precision(buffer, token);
	misc_itoa((unsigned long) number, buffer, "0123456789");
	printnum(carriage, token, buffer, prefix);
}

void	printuns(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned long	number;
	char			buffer[128];
	char			*prefix;
	
	number = (unsigned long) va_arg(ap, unsigned int);
	prefix = get_prefix(token, number);
	fill_precision(buffer, token);
	misc_itoa(number, buffer, "0123456789");
	printnum(carriage, token, buffer, prefix);
}
