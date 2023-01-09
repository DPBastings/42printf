/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printlit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 12:08:52 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 10:42:54 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"

void	printlit(t_carriage *carriage, t_token *token, va_list ap)
{
	(void) ap;
	carriage->print(carriage, (char *) &(token->flags), 1);
}
