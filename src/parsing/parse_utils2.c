/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:12 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:23:52 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*th_tokennew(int type, char *str)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!(node))
		return (NULL);
	node->type = type;
	node->str = str;
	return (node);
}

t_env	*th_envnew(char *line)
{
	t_env	*node;
	int		i;

	node = (t_env *)malloc(sizeof(t_env));
	if (node == NULL)
		return (NULL);
	node->initial_line = line;
	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			break ;
		i++;
	}
	node->key = ft_substr(line, 0, i);
	node->value = ft_substr(line, i + 1, ft_strlen(line) - i);
	check_shlvl(node);
	if (!node->key || !node->value)
		return (NULL);
	return (node);
}

void	print_error(char *message)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
}

t_node_cmd	*find_file_path(t_list *tmp, int *cnt)
{
	t_node_cmd	*ret;

	ret = NULL;
	while (((t_token *)(tmp->content))->type != T_PIPE)
	{
		if (((t_token *)(tmp->content))->type == T_REDIRECT)
			tmp = tmp->next->next;
		else
		{
			if (*cnt == 0)
			{
				ret = (t_node_cmd *)malloc(sizeof(t_node_cmd));
				malloc_null_guard(ret);
				ret->file_path = ft_strdup(((t_token *)(tmp->content))->str);
				malloc_null_guard(ret->file_path);
			}
			(*cnt)++;
			tmp = tmp->next;
		}
	}
	return (ret);
}
