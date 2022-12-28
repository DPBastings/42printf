/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_token.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 15:14:20 by dbasting      #+#    #+#                 */
/*   Updated: 2022/12/13 16:33:34 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "token.h"
#include <stddef.h>

static t_printer	g_printdict[] = {
	printlit,
	printdec,
	printdec,
	printoct,
	printuns,
	printhex,
	printhex,
	printchr,
	printstr,
	printptr,
	printpercent
};

int	expand_token(t_carriage *carriage, t_token *token, va_list ap)
{
	if (token == NULL)
		return (0);
	g_printdict[token->specifier](carriage, token, ap);
	return (1);
}
