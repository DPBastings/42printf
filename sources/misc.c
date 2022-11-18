/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:46:13 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 12:06:56 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"
#include "../libft/libft.h"

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	misc_atoi(char const **str)
{
	int	number;
	
	number = 0;
	while (ft_isspace(**str))
		(*str)++;
	while (ft_isdigit(**str))
	{
		number *= 10;
		number += **str - '0';
		(*str)++;
	}
	return (number);
}
