/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_str_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:29 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:12:26 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**env_list_to_str_ptr(t_list *env_list);
static int	env_list_len(t_list *env_list);

char	**env_list_to_str_ptr(t_list *env_list)
{
	int		p_len;
	t_list	*tmp;
	char	**env_p;

	p_len = env_list_len(env_list);
	if (p_len == 0)
		return (0);
	env_p = (char **)malloc(sizeof(char *) * (p_len + 1));
	p_len = 0;
	tmp = env_list;
	while (tmp)
	{
		if (((t_env *)(tmp->content))->value)
			env_p[p_len++] = ft_strdup(((t_env *)(tmp->content))->initial_line);
		tmp = tmp->next;
	}
	env_p[p_len] = 0;
	return (env_p);
}

static int	env_list_len(t_list *env_list)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = env_list;
	while (tmp)
	{
		if (((t_env *)(tmp->content))->value)
			len++;
		tmp = tmp->next;
	}
	return (len);
}
