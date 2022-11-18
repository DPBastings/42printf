/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_token.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 15:14:20 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/18 15:07:56 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "token.h"

t_printer const	g_printdict[] = {
	printlit,
	printdec,
	printdec,
	printuns,
	printhex,
	printhex,
	printchr,
	printstr,
	printpercent
};

void	expand_token(t_carriage *carriage, t_token *token, va_list ap)
{
	g_printdict[token->specifier](carriage, token, ap);
}
