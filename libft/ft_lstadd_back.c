/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:58:19 by rhong             #+#    #+#             */
/*   Updated: 2022/04/10 13:00:12 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*now_node;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	now_node = *lst;
	while (now_node->next)
		now_node = now_node->next;
	now_node->next = new;
}
