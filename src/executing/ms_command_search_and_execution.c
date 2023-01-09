/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_command_search_and_execution.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:38 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 14:24:03 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_command_search_and_execution(t_node_cmd *n_cmd, \
t_ms_exec_data *data);
void		pipe_closing(t_ms_exec_data *data);

void	ms_command_search_and_execution(t_node_cmd *n_cmd, t_ms_exec_data *data)
{
	int		builtin_flag;
	char	**env_str_ptr;
	char	*tmp;

	builtin_flag = 0;
	env_str_ptr = env_list_to_str_ptr(data->env_list);
	tmp = n_cmd->file_path;
	n_cmd->file_path = find_cmd_path(env_str_ptr, n_cmd->file_path, \
	&builtin_flag);
	if (tmp != n_cmd->file_path)
		free(tmp);
	if (data->cmd_num == 1 && builtin_flag > 3)
	{
		do_builtin_2(n_cmd->argv, data, builtin_flag);
		free_str_ptr(env_str_ptr);
		return ;
	}
	data->pids[data->fork_cnt] = fork();
	if (data->pids[data->fork_cnt] == 0)
		cmd_exec_child(n_cmd, builtin_flag, env_str_ptr, data);
	free_str_ptr(env_str_ptr);
}

void	pipe_closing(t_ms_exec_data *data)
{
	if (data->cmd_num != 1)
	{
		if (data->pipes_fd[data->fork_cnt % 2][1])
			close(data->pipes_fd[data->fork_cnt % 2][1]);
		data->pipes_fd[data->fork_cnt % 2][1] = 0;
		if (data->pipes_fd[(data->fork_cnt + 1) % 2][0])
			close(data->pipes_fd[(data->fork_cnt + 1) % 2][0]);
		data->pipes_fd[(data->fork_cnt + 1) % 2][0] = 0;
		if (data->fork_cnt == data->cmd_num - 1 && \
		data->pipes_fd[(data->fork_cnt) % 2][0])
		{
			close(data->pipes_fd[(data->fork_cnt) % 2][0]);
			data->pipes_fd[(data->fork_cnt) % 2][0] = 0;
		}
	}
	data->fork_cnt++;
}
