/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printdec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:12:09 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 16:35:38 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.c"
#include <stdarg.h>

void	printdec(t_carriage *carriage, t_token *token, va_list ap)
{
	(void) carriage;
	(void) token;
	(void) ap;
}

void	printuns(t_carriage *carriage, t_token *token, va_list ap)
{
	printdec(carriage, token, ap);
}
