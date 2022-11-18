/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriage.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:24:58 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/18 13:15:50 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

void	print(t_carriage *self, char *str, size_t len)
{
	size_t	old_written;

	old_written = self->written;
	write(self->paper, str++, len);
	self->written += len;
	printf("\n%zd new chars have been written (total: %zd)\n", self->written - old_written, self->written);
}
