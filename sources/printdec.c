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

static void	printnum(t_carriage *carriage, t_token *token, char *buffer)
{
	size_t	len;
	int		neg;
	
	len = ft_strlen(buffer);
	neg = (buffer[0] == '-');

	print(carriage, buffer, neg);
	pad_left(carriage, token, len);
	print(carriage, buffer + neg, len - neg);
	pad_right(carriage, token, len);
}

void	printdec(t_carriage *carriage, t_token *token, va_list ap)
{
	long			argval;
	unsigned long	number;
	char			buffer[128];
	
	argval = (long) va_arg(ap, int);
	if (argval < 0)
	{
		buffer[0] = '-';
		number = (unsigned long) -argval;
	}
	else
		number = (unsigned long) argval;
	misc_itoa(number, buffer + (argval < 0), "0123456789");
	printnum(carriage, token, buffer);
}

void	printuns(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned long	number;
	char			buffer[128];
	
	number = (unsigned long) va_arg(ap, unsigned int);
	misc_itoa(number, buffer, "0123456789");
	printnum(carriage, token, buffer);
}
