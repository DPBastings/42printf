/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 14:07:42 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 18:25:34 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "carriage.h"
#include "token.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*static void	printtoken(t_token *token)
{
	printf("token at %p:\n", token);
	if (token->specifier)
	{
		printf(">     flags: ");
		if (token->flags & FLAG_ALTERNATIVE)
			printf("# ");
		if (token->flags & FLAG_ZEROPADDING)
			printf("0 ");
		if (token->flags & FLAG_LEFTALIGN)
			printf("- ");
		if (token->flags & FLAG_SPACE)
			printf("space ");
		if (token->flags & FLAG_SIGNED)
			printf("+");
		printf("\n");
		printf(">     width: %zu\n", token->field_width);
		printf("> precision: %zd\n", token->precision);
		printf("> specifier: %d\n", token->specifier);
	}
	else
		printf(">   literal: '%c'\n", token->flags);
}*/

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
	printf("%zu tokens have been processed\n", counter);
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
