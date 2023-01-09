/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:31 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:14:55 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ms_unset(char **av, t_ms_exec_data *data);
static t_list	*find_before_list_node(t_list *list, t_list *node);
static void		free_env_list_node(t_list *env_node);

int	ms_unset(char **av, t_ms_exec_data *data)
{
	int		av_cnt;
	t_list	*env_node;
	t_list	*before_node;

	av_cnt = 1;
	while (av[av_cnt])
	{
		env_node = find_env_by_name_in_list(data->env_list, av[av_cnt]);
		if (env_node)
		{
			if (env_node == data->env_list)
				data->env_list = env_node->next;
			else
			{
				before_node = find_before_list_node(data->env_list, env_node);
				before_node->next = env_node->next;
			}
			free_env_list_node(env_node);
		}
		av_cnt++;
	}
	return (0);
}

static t_list	*find_before_list_node(t_list *list, t_list *node)
{
	t_list	*ret;

	ret = list;
	while (ret)
	{
		if (ret->next == node)
			return (ret);
		ret = ret->next;
	}
	return (0);
}

static void	free_env_list_node(t_list *env_node)
{
	free(((t_env *)env_node->content)->initial_line);
	free(((t_env *)env_node->content)->key);
	free(((t_env *)env_node->content)->value);
	free(env_node->content);
	free(env_node);
}
