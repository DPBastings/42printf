/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printhex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 15:09:02 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 16:52:20 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/carriage.h"
#include "../libft/libft.h"
#include <stdarg.h>

char const	hexdigits_low[] = "0123456789abcdef";
char const	hexdigits_upp[] = "0123456789ABCDEF";

void	printhex(t_carriage *carriage, t_token *token, va_list ap)
{
	(void) carriage;
	(void) token;
	(void) ap;
}

void	printptr(t_carriage *carriage, t_token *token, va_list ap)
{
	printhex(carriage, token, ap);
}
