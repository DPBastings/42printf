/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 16:47:59 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 14:26:21 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "../headers/libftprintf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int	main(void)
{
	char	*ptr;

	ptr = ft_strdup("lasciate ogne speranza, voi ch'intrate");
	test("ptr: NULL [%p]", NULL);
	test("ptr: NULL; precision < 5 [%.3p]", NULL);
	test("ptr: NULL; precision >= 5 [%.6p]", NULL);
	test("ptr: precision = 8 [%.8p]", ptr);	
	return (0);
}
