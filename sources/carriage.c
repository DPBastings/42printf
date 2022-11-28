/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriage.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:24:58 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 15:27:54 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include <stddef.h>
#include <unistd.h>

void	print(t_carriage *self, char *str, size_t len)
{
	write(self->paper, str++, len);
	self->printed += len;
}
