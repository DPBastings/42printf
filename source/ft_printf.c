/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 14:07:42 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/16 15:33:32 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "carriage.h"
#include "token.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_vdprintf(int fd, char const *format, va_list ap)
{
	t_carriage	carriage;
	t_token		*token;

	carriage.print = print;
	carriage.printed = 0;
	carriage.paper = fd;
	while (*format && carriage.printed != -1)
	{
		token = parser(&format);
		if (!(expand_token(&carriage, token, ap)))
			carriage.printed = -1;
		free(token);
	}
	va_end(ap);
	return (carriage.printed);
}

int	ft_vprintf(char const *format, va_list ap)
{
	int	ret;

	ret = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, char const *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (ret);
}
