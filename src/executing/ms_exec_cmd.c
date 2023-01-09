/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:42 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:13:06 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	red_error_execution(t_ms_exec_data *data);
static void	no_cmd_execution(t_ms_exec_data *data);

t_list	*ms_exec_cmd(t_cmd_tree *cmd_input, t_list *env_list, t_list *tmp_files)
{
	t_ms_exec_data	*data;
	t_cmd_tree		*parser;
	t_list			*ret_env;

	data = ms_exec_cmd_init(cmd_input, env_list);
	parser = data->c_tree;
	while (parser)
	{
		if (ms_simple_command_expansion(parser->n_exec, data) == ERROR)
			red_error_execution(data);
		else if (!parser->n_exec->n_cmd)
			no_cmd_execution(data);
		else
			ms_command_search_and_execution(parser->n_exec->n_cmd, data);
		pipe_closing(data);
		parser = parser->n_pipe;
	}
	ms_wait_all(data->pids, data->fork_cnt);
	ms_set_back(data->std_fd, tmp_files);
	ret_env = data->env_list;
	ms_free_data(data);
	return (ret_env);
}

static void	red_error_execution(t_ms_exec_data *data)
{
	data->pids[data->fork_cnt] = fork();
	if (data->pids[data->fork_cnt] == 0)
		exit(1);
}

static void	no_cmd_execution(t_ms_exec_data *data)
{
	data->pids[data->fork_cnt] = fork();
	if (data->pids[data->fork_cnt] == 0)
		exit(0);
}
