/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 14:07:42 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 16:03:37 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "carriage.h"
#include "token.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_vdprintf(int fd, char const *format, va_list ap)
{
	t_carriage	carriage;
	t_token		*token;
	size_t		counter;

	carriage.written = 0;
	carriage.paper = fd;
	counter = 0;
	while (*format)
	{
		token = parser(&format);
		expand_token(&carriage, token, ap);
		free(token);
		counter++;
	}
	va_end(ap);
	return (carriage.written);
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
