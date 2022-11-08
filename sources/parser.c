/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:58:51 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/08 13:33:12 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parser.h"
#include "../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

/*static void destroy_converter(t_converter *converter)
{
	free(converter);
}*/

t_list	*parser(char const *format)
{
	char const	**tracker;
	t_list		*converters;
	t_converter	*new;

	converters = NULL;
	tracker = &format;
	while (**tracker)
	{
		if (**tracker == '%')
		{
			(*tracker)++;
			new = get_converter(tracker);
			if (new)
				ft_lstadd_back(&converters, ft_lstnew(new));
			else
				continue ;
		}
		(*tracker)++;
	}
	return (converters);
}
