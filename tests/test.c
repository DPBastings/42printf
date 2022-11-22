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

#include "printtoken.h"
#include "../headers/libftprintf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	print_len(int num)
{
	printf(" (len = %d)\n", num);
}

int	main(void)
{
	char			*string;
	int				printed;

	string = ft_strdup("gekke geit");
	printed = ft_printf("%15p", string);
	print_len(printed);
	printed = printf("%15p", string);
	print_len(printed);
	printed = ft_printf("%25d", 10);
	print_len(printed);
	printed = printf("%25d", 10);
	print_len(printed);
	printed = ft_printf("%.x", 0);
	print_len(printed);
	printed = printf("%.x", 0);
	print_len(printed);
	free(string);
	return (0);
}
