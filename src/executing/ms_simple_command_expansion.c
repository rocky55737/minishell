/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_simple_command_expansion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:47 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 18:13:25 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ms_simple_command_expansion(t_node_exec *n_exec, \
t_ms_exec_data *data);
static int	ms_redirection(t_node_redirects *n_reds, \
t_ms_exec_data *data);
static void	ms_pipe(t_ms_exec_data *data);
static void	dups(t_ms_exec_data *p_data, int fork_cnt);

int	ms_simple_command_expansion(t_node_exec *n_exec, t_ms_exec_data *data)
{
	if (ms_redirection(n_exec->n_reds, data) == ERROR)
		return (ERROR);
	return (0);
}

static void	ms_pipe(t_ms_exec_data *data)
{
	if (data->cmd_num == 1)
		return ;
	if (data->fork_cnt < data->cmd_num)
	{
		close_pipes(data->pipes_fd[data->fork_cnt % 2]);
		pipe(data->pipes_fd[data->fork_cnt % 2]);
		dups(data, data->fork_cnt);
	}
}

static void	dups(t_ms_exec_data *data, int fork_cnt)
{
	if (fork_cnt == 0)
	{
		dup2(data->pipes_fd[0][1], 1);
	}
	else if (fork_cnt == data->cmd_num - 1)
	{
		dup2(data->pipes_fd[(fork_cnt + 1) % 2][0], 0);
		dup2(data->std_fd[1], 1);
	}
	else
	{
		dup2(data->pipes_fd[(fork_cnt + 1) % 2][0], 0);
		dup2(data->pipes_fd[fork_cnt % 2][1], 1);
	}
}

static int	ms_redirection(t_node_redirects *n_reds, t_ms_exec_data *data)
{
	int	in_file_fd;
	int	out_file_fd;
	int	ret;

	ret = 0;
	in_file_fd = 0;
	out_file_fd = 0;
	ret = recursive_red(n_reds, &in_file_fd, &out_file_fd);
	ms_pipe(data);
	if (ret == ERROR)
		return (ERROR);
	if (in_file_fd)
	{
		dup2(in_file_fd, 0);
	}
	if (out_file_fd)
	{
		dup2(out_file_fd, 1);
	}
	return (0);
}
