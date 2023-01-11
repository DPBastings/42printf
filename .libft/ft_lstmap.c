/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 13:00:17 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/04 13:31:09 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapping;
	t_list	*newnode;
	void	*newcontent;

	if (!f || !del)
		return (NULL);
	mapping = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (newnode == NULL)
		{
			ft_lstclear(&mapping, del);
			del(newcontent);
			break ;
		}
		ft_lstadd_back(&mapping, newnode);
		lst = lst->next;
	}
	return (mapping);
}
