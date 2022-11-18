/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsetest.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:32:54 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 14:40:56 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libftprintf.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_printf(argv[1]);
	return (0);
}
