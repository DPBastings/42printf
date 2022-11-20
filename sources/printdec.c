/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printdec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:12:09 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 16:35:38 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include "../libft/libft.h"
#include <stdarg.h>

void	printdec(t_carriage *carriage, t_token *token, va_list ap)
{
	long	number;
	char	buffer[128];
	size_t	len;
	
	number = (long) va_arg(ap, long);
	misc_itoa(number, buffer, "0123456789");
	len = ft_strlen(buffer);
	pad_left(carriage, token, len);
	print(carriage, buffer, len);
	pad_right(carriage, token, len);
}

void	printuns(t_carriage *carriage, t_token *token, va_list ap)
{
	printdec(carriage, token, ap);
}
