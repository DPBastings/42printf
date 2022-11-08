/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_converter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 15:00:57 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/08 14:11:16 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parser.h"
#include "../headers/misc.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	parse_flags(t_converter *converter, char const **format)
{
	while (ft_strchr(FLAGS, **format))
	{
		if (**format == '#')
			converter->flags |= FLAG_ALTERNATIVE;
		else if (**format == '0')
			converter->flags |= FLAG_ZEROPADDING;
		else if (**format == '-')
			converter->flags |= FLAG_LEFTALIGN;
		else if (**format == ' ')
			converter->flags |= FLAG_SPACE;
		else if (**format == '+')
			converter->flags |= FLAG_SIGNED;
		(*format)++;
	}
	return (1);
}

static int	parse_field_width(t_converter *converter, char const **format)
{
	converter->field_width = misc_atoi(format);
	return (1);
}

static int	parse_precision(t_converter *converter, char const **format)
{
	if (**format == '.')
	{
		(*format)++;
		converter->precision += misc_atoi(format);
	}
	else
		converter->precision = -1;
	return (1);
}

static int	parse_specifier(t_converter *converter, char const **format)
{
	if (ft_strchr(SPECIFIERS, **format))
	{
		converter->specifier = **format;
		return (1);
	}
	return (0);
}

t_converter	*get_converter(char const **format)
{
	t_converter	*converter;

	converter = ft_calloc(1, sizeof(t_converter));
	if (converter == NULL)
		return (NULL);
	parse_flags(converter, format);
	parse_field_width(converter, format);
	parse_precision(converter, format);
	if (!parse_specifier(converter, format))
	{
		free(converter);
		return (NULL);
	}
	return (converter);
}
