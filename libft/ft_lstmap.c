/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matej <matej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:06:34 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/11 11:28:16 by matej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	t_list	*list;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	list = lst;
	while (list)
	{
		content = f(list->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		list = list->next;
	}
	return (head);
}
/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_list;
	t_list	*temp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	temp = lst;
	while (temp)
	{
		content = f(temp->content);
		node = ft_lstnew(content);
		if (!node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		temp = temp->next;
	}
	return (new_list);
} */