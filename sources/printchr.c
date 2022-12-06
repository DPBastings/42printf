/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printchr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:50:22 by dbasting      #+#    #+#                 */
/*   Updated: 2022/12/06 10:30:00 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/carriage.h"
#include "../headers/token.h"
#include <stdarg.h>
#include <unistd.h>

void	printpercent(t_carriage *carriage, t_token *token, va_list ap)
{
	(void) ap;
	pad_left(carriage, token, 1);
	carriage->print(carriage, "%", 1);
	pad_right(carriage, token, 1);
}

void	printchr(t_carriage *carriage, t_token *token, va_list ap)
{
	char	c;

	c = (char) va_arg(ap, int);
	pad_left(carriage, token, 1);
	carriage->print(carriage, &c, 1);
	pad_right(carriage, token, 1);
}
