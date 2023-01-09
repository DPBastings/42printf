/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 16:47:59 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/09 17:08:21 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int	main(void)
{
	test("%0o", 123456);
	test("%#.5o", -123456);
	return (0);
}
