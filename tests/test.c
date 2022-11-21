/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 16:47:59 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 17:29:18 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

static void	print_len(int num)
{
	printf(" (len = %d)\n", num);
}

int	main(void)
{
	char			*string;
	int				integer;
	unsigned int	unsigned_integer;
	int				printed;

	string = ft_strdup("gekke geit");
	integer = -1685;
	unsigned_integer = 2147483648;
	printed = ft_printf("%15p", string);
	print_len(printed);
	printed = printf("%15p", string);
	print_len(printed);
	printed = ft_printf("%u", integer);
	print_len(printed);
	printed = printf("%u", integer);
	print_len(printed);
	printed = ft_printf("%0-15u", unsigned_integer);
	print_len(printed);
	printed = printf("%-15u", unsigned_integer);
	print_len(printed);
	return (0);
}
