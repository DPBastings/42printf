/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 16:47:59 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/09 17:09:02 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	print_len(int num)
{
	printf(" (len = %d)\n", num);
}

void	test(char *format, ...)
{
	va_list	ap;
	va_list	ap_copy;
	
	va_start(ap, format);
	va_copy(ap_copy, ap);
	printf("original:\n");
	print_len(vprintf(format, ap_copy));
	printf("knockoff:\n");
	print_len(ft_vprintf(format, ap));
}
