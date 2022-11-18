/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 16:47:59 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 18:19:32 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

static void	funclet(int num)
{
	printf("(len = %d)\n", num);
}

int	main(void)
{
	char	*string;
	int		printed;

	string = ft_strdup("gekke geit");
	printed = ft_printf("%.5s", string);
	funclet(printed);
	printed = printf("%.5s", string);
	funclet(printed);
	return (0);
}
