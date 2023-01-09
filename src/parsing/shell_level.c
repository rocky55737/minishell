/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:18 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:18 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_env_shlvl_line(t_env *node)
{
	char	*key_equal;
	char	*new_line;

	if (!node->key || !node->value)
		return ;
	key_equal = ft_strjoin(node->key, "=");
	new_line = ft_strjoin_free(key_equal, node->value);
	malloc_null_guard(new_line);
	free(node->initial_line);
	node->initial_line = new_line;
}

static int	is_shlvl_num(char *value)
{
	int	i;

	i = 0;
	if (value[i] == '-')
		i++;
	if (value[i] == '\0')
		return (FALSE);
	while (value[i])
	{
		if (ft_isdigit(value[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	check_shlvl(t_env *node)
{
	int		curr_level;
	char	*next_level;

	curr_level = 0;
	if (ft_strcmp(node->key, "SHLVL"))
		return ;
	if (is_shlvl_num(node->value) == FALSE)
	{
		free(node->value);
		node->value = ft_strdup("1");
	}
	else
	{
		curr_level = ft_atoi(node->value);
		if (curr_level < 0)
			next_level = ft_strdup("0");
		else
			next_level = ft_itoa(curr_level + 1);
		free(node->value);
		node->value = next_level;
	}
	set_env_shlvl_line(node);
}
