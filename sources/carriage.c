/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriage.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:24:58 by dbasting      #+#    #+#                 */
/*   Updated: 2022/12/06 12:27:07 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include <stddef.h>
#include <unistd.h>

void	print(t_carriage *self, char *str, size_t len)
{
	if (self->printed != -1 && str)
	{
		if (write(self->paper, str++, len) != -1)
			self->printed += len;
		else
			self->printed = -1;
	}
	else
		self->printed = -1;
}
