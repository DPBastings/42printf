/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 12:06:21 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/08 12:51:40 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parser.h"
#include "../libft/libft.h"
#include <stdio.h>

static void	putconverter(t_converter *converter)
{
	printf("Converter at %p:\n", converter);
	printf("> flags:       %d\n", converter->flags);
	printf("> field width: %d\n", converter->field_width);
	printf("> precision:   %d\n", converter->precision);
	printf("> specifier:   %c\n", converter->specifier);
}

int	main(int argc, char **argv)
{
	t_list	*converters;

	if (argc == 2)
	{
		converters = parser(argv[1]);
		while (converters)
		{
			putconverter(converters->content);
			converters = converters->next;
		}
	}
	return (0);
}
