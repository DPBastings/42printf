/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 12:51:57 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/21 13:47:46 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*previous;

	while (*lst)
	{
		previous = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(previous, del);
	}
}
