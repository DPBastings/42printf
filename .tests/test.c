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

#include "printtoken.h"
#include "../headers/libftprintf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

static void	print_len(int num)
{
	printf(" (len = %d)\n", num);
}

static void	test(char *format, ...)
{
	va_list	ap;
	va_list	ap_copy;
	
	va_start(ap, format);
	va_copy(ap_copy, ap);
	printf("knockoff:\n");
	print_len(ft_vprintf(format, ap));
	printf("original:\n");
	print_len(vprintf(format, ap_copy));
}

int	main(void)
{
	char	*ptr;

	ptr = ft_strdup("lasciate ogne speranza, voi ch'intrate");
	test("int: zeropad + precision [%010.5d]", -26);
	test("int: leftalign + precision [%-.5d]", -26);
	test("ptr: zeropad [%0p]", ptr);
	test("str: NULL; zeropad + precision < 6 [%0.3s]", NULL);
	test("int: limits [%i] [%i]", INT_MAX, INT_MIN);
	test("hex: 0; alternative [%#x] [%#X]", 0, 0);
	test("hex: limits; alternative [%#x] [%#x] [%#x] [%#x]", INT_MAX, INT_MIN, LONG_MAX,LONG_MIN);
	test("percent: leftalign + zeropad + minwidth = 5 [%-05%]");
	test("int: zeropad + leftalign + precision [%0-.10d]", 1685);
	test("int: 0; precision = 0 [%.0d]", 0);
	test("hex: 0; precision = 0 [%.0x]", 0);
	test("hex: 0; precision = 0 + alternative [%#.0x]", 0);
	test("int: 1685; precision = 0 [%.0d]", 1685);
	test("hex: 1685; precision = 0 [%.0x]", 1685);
	test("hex: 1685; precision = 0 + alternative [%#.0x]", 1685);
	test("int: INT_MIN, minwidth [%020d]", INT_MIN);
	return (0);
}
