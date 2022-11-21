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
#include <stdlib.h>

static char		*prefix;
static size_t	prefix_len;

static void	printnum(t_carriage *carriage, t_token *token, char *buffer)
{
	size_t	len;
	
	len = ft_strlen(buffer);
	if (HAS_FLAG(token, FLAG_ZEROPADDING))
	{
		print(carriage, prefix, prefix_len);
		pad_left(carriage, token, len + prefix_len);
	}
	else
	{
		pad_left(carriage, token, len + prefix_len);
		print(carriage, prefix, prefix_len);
	}
	free(prefix);
	print(carriage, buffer, len);
	pad_right(carriage, token, len);
}

/*static void	add_prefix(char *buffer, char const *prefix)
{
	while (*prefix)
		*buffer++ = *prefix++;
}*/
		

void	printhex(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned long	number;
	char			buffer[128];

	number = (unsigned long) va_arg(ap, int);
	prefix_len = (HAS_FLAG(token, FLAG_ALTERNATIVE) && number != 0) * 2;
	if (token->specifier == SPEC_HEXUPP)
	{
		if (prefix_len)
			prefix = ft_strdup("0X");
		misc_itoa(number, buffer, "0123456789ABCDEF");
	}
	else
	{
		if (prefix_len)
			prefix = ft_strdup("0x");
		misc_itoa(number, buffer, "0123456789abcdef");
	}
	printnum(carriage, token, buffer);
}

void	printptr(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned long	number;
	char			buffer[128];

	number = (unsigned long) va_arg(ap, void *);
	prefix = ft_strdup("0x");
	prefix_len = 2;
	misc_itoa(number, buffer, "0123456789abcdef");
	printnum(carriage, token, buffer);
}
