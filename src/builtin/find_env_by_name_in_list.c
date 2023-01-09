/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_by_name_in_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:59 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:13:11 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_env_by_name_in_list(t_list *env_list, char *name)
{
	t_list	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strcmp(((t_env *)(tmp->content))->key, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}
