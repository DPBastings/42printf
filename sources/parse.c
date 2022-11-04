/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:58:51 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/04 14:06:56 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void	*ft_free(char **array)
{
	while (*array)
		free(*array++);
	free(array);
	return (NULL);
}

static char	*isspecifier(const char *c)
{
	char	*specifiers;
	size_t	index;

	specifiers = ft_strdup(CONVERSION_SPECIFIERS);
	if (*c == '%')
	{
		index = 0;
		while (specifiers[index])
		{
			if (*(c + 1) == specifiers[index])
				return (ft_substr(c, 0, 1));
			index++;
		}
	}
	return (NULL);
}

static char	**parse(const char *format)
{
	size_t	index;
	size_t	count;
	char	*array;

	index = 0;
	count = 0;
	while (format[index])
	{
		if (isflag(format + index))
			count++;
		index++;
	}
	array = malloc(count + 1 * sizeof(char *));
	if (array == NULL)
		return (NULL);
	index = 0;
	count = 0;
	while (format[index])
	{
		array[count] = 
		if (array[count] == NULL)
			return (ft_free(array));
		
	}
	return (array);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	va_list	ap;

	(void) ap;
	index = 0;
	while (*format)
	{
		if (*format
		format++;
	}
	return (index);
}

int	main(void)
{
	char	*array;

	array = parse("L%orem %i%p%s%um %dolor %s%it ame%t%%.");
	ft_putendl_fd(array, 1);
	return (0);
}
