/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:25 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 14:35:48 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		cmd_exec_child(t_node_cmd *n_cmd, \
int builtin_flag, char **env, t_ms_exec_data *data);
void		close_pipes(int fd_arr[2]);
static void	command_not_found(char *cmd);

void	cmd_exec_child(t_node_cmd *n_cmd, \
int builtin_flag, char **env, t_ms_exec_data *data)
{
	allow_control_character();
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (data->fork_cnt < data->cmd_num)
		close_pipes(data->pipes_fd[data->fork_cnt]);
	if (data->fork_cnt > 0)
		close_pipes(data->pipes_fd[(data->fork_cnt + 1) % 2]);
	if (builtin_flag)
		do_builtin_1(n_cmd->argv, data, builtin_flag);
	execve(n_cmd->file_path, n_cmd->argv, env);
	command_not_found(n_cmd->argv[0]);
}

void	close_pipes(int fd_arr[2])
{
	if (fd_arr[0] != 0)
		close(fd_arr[0]);
	fd_arr[0] = 0;
	if (fd_arr[1] != 0)
		close(fd_arr[1]);
	fd_arr[1] = 0;
}

static void	command_not_found(char *cmd)
{
	char	*buff;

	buff = ft_strdup("minishell: ");
	buff = ft_strjoin_free(ft_strjoin_free(buff, cmd), ": command not found\n");
	write(2, buff, ft_strlen(buff));
	exit(127);
}
