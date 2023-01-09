/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:39 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:14:47 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ms_export(char **av, t_ms_exec_data *data);
static int	ms_export_show_env(t_ms_exec_data *data);
static char	*get_var_name(char *initial_line);
static char	*get_var_value(char *initail_line);
static	void	do_export(char *arg, t_ms_exec_data *data, \
char *var_name, char *var_value);

int	ms_export(char **av, t_ms_exec_data *data)
{
	int		av_cnt;
	char	*var_name;
	char	*var_value;
	int		exit_code;

	var_value = NULL;
	if (str_ptr_len(av) == 1)
		return (ms_export_show_env(data));
	exit_code = 0;
	av_cnt = 1;
	while (av[av_cnt])
	{
		var_name = get_var_name(av[av_cnt]);
		if (!can_be_name(var_name))
		{
			ms_export_err(var_name);
			exit_code = 1;
		}
		if (data->cmd_num == 1)
			do_export(av[av_cnt], data, var_name, var_value);
		av_cnt++;
	}
	return (exit_code);
}

static int	ms_export_show_env(t_ms_exec_data *data)
{
	t_list	*tmp;

	tmp = data->env_list;
	while (tmp)
	{
		printf("declare -x %s", ((t_env *)(tmp->content))->key);
		if (((t_env *)(tmp->content))->value)
			printf("=\"%s\"", ((t_env *)(tmp->content))->value);
		printf("\n");
		tmp = tmp->next;
	}
	return (0);
}

static char	*get_var_name(char *initial_line)
{
	int		cnt;
	char	*name;

	cnt = 0;
	while (initial_line[cnt] && initial_line[cnt] != '=')
		cnt++;
	name = ft_substr(initial_line, 0, cnt);
	return (name);
}

static char	*get_var_value(char *initail_line)
{
	char	*equal_pos;

	equal_pos = ft_strchr(initail_line, '=');
	if (equal_pos == 0)
		return (0);
	return (ft_strdup(equal_pos + 1));
}

static	void	do_export(char *arg, t_ms_exec_data *data, \
char *var_name, char *var_value)
{
	t_list	*env_node;
	t_env	*env;

	env_node = find_env_by_name_in_list(data->env_list, var_name);
	var_value = get_var_value(arg);
	if (env_node)
	{
		free(var_name);
		free(((t_env *)(env_node->content))->initial_line);
		((t_env *)(env_node->content))->initial_line = ft_strdup(arg);
		if (var_value)
		{
			free(((t_env *)(env_node->content))->value);
			((t_env *)(env_node->content))->value = var_value;
		}
	}
	else
	{
		env = (t_env *)malloc(sizeof(t_env));
		malloc_null_guard(env);
		env->initial_line = ft_strdup(arg);
		env->key = var_name;
		env->value = var_value;
		ft_lstadd_back(&data->env_list, ft_lstnew(env));
	}
}
