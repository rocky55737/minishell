/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:11:04 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:07 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_env_list(t_list **env_list, char **envp)
{
	t_list	*new_node;
	t_env	*new_env;
	char	*line;
	int		i;

	*env_list = NULL;
	i = 0;
	while (envp[i])
	{
		line = ft_strdup(envp[i]);
		malloc_null_guard(line);
		new_env = th_envnew(line);
		malloc_null_guard(new_env);
		new_node = ft_lstnew(new_env);
		malloc_null_guard(new_node);
		ft_lstadd_back(env_list, new_node);
		i++;
	}
}

int	init(t_list **env_list, char **envp)
{
	if (init_signal())
		return (ERROR);
	init_env_list(env_list, envp);
	return (0);
}
