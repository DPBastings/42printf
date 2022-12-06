/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 16:47:59 by dbasting      #+#    #+#                 */
/*   Updated: 2022/12/06 10:28:11 by dbasting      ########   odam.nl         */
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
	test("%5%");
	test("%-5%");
	test("%-05%");
	test("%05%");
	test("%.5%");
	test("%12%");
	test("%-12%");
	test("%; conversie was kaputtski");
	test("conversie is kaputtski: %0");
	return (0);
}
