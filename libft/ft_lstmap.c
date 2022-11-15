/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:19:29 by rhong             #+#    #+#             */
/*   Updated: 2022/04/10 13:41:56 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_lst;
	t_list	*new_lst;

	mapped_lst = 0;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&mapped_lst, del);
			return (0);
		}
		ft_lstadd_back(&mapped_lst, new_lst);
		lst = lst->next;
	}
	new_lst = 0;
	return (mapped_lst);
}
