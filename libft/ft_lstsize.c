/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:52:36 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/09 13:48:40 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	if (!lst)
		return (count);
	temp = lst;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

/* int	main(void)
{
	t_list *head = NULL;
	t_list *n1, *n2, *n3;
	n1 = ft_lstnew("n1");
	ft_lstadd_front(&head, n1);
	n2 = ft_lstnew("n2");
	ft_lstadd_front(&head, n2);
	n3 = ft_lstnew("n3");
	ft_lstadd_front(&head, n3);

	printf("list size: %d\n", ft_lstsize(head));
} */