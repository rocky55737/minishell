/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_cmd_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:40 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 16:44:23 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ms_exec_data	*ms_exec_cmd_init(t_cmd_tree *cmd_input, t_list *env_list);
static int		pipe_node_len(t_node_pipe	*n_pipe);
void			child_sig_handler(int sig_n);

t_ms_exec_data	*ms_exec_cmd_init(t_cmd_tree *cmd_input, t_list *env_list)
{
	t_ms_exec_data	*data;

	data = (t_ms_exec_data *)malloc(sizeof(t_ms_exec_data));
	malloc_null_guard(data);
	data->c_tree = cmd_input;
	data->cmd_num = pipe_node_len(cmd_input);
	data->env_list = env_list;
	data->fork_cnt = 0;
	data->std_fd[0] = open("/dev/stdin", O_RDONLY, 0644);
	data->std_fd[1] = open("/dev/stdout", O_WRONLY, 0644);
	ft_bzero(data->pipes_fd, sizeof(int) * 4);
	data->pids = (pid_t *)ft_calloc(data->cmd_num, sizeof(pid_t));
	malloc_null_guard(data->pids);
	signal(SIGINT, SIG_IGN);
	return (data);
}

static int	pipe_node_len(t_node_pipe	*n_pipe)
{
	int	len;

	len = 0;
	while (n_pipe)
	{
		len++;
		n_pipe = n_pipe->n_pipe;
	}
	return (len);
}
