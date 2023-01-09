/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:44 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:13:09 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_free_data(t_ms_exec_data *data);
static void	free_pipe_node(t_node_pipe *n_p);
static void	free_exec_node(t_node_exec *n_e);
static void	free_reds_node(t_node_redirects *n_rs);
static void	free_cmd_node(t_node_cmd *n_c);

void	ms_free_data(t_ms_exec_data *data)
{
	free_pipe_node(data->c_tree);
	free(data->pids);
	free(data);
}

static void	free_pipe_node(t_node_pipe *n_p)
{
	if (n_p == 0)
		return ;
	free_exec_node(n_p->n_exec);
	free_pipe_node(n_p->n_pipe);
	free(n_p);
}

static void	free_exec_node(t_node_exec *n_e)
{
	if (n_e == 0)
		return ;
	free_reds_node(n_e->n_reds);
	free_cmd_node(n_e->n_cmd);
	free(n_e);
}

static void	free_reds_node(t_node_redirects *n_rs)
{
	if (n_rs == 0)
		return ;
	free_reds_node(n_rs->n_reds);
	if (n_rs->n_red)
	{
		free(n_rs->n_red->file_name);
		free(n_rs->n_red);
	}
	free(n_rs);
}

static void	free_cmd_node(t_node_cmd *n_c)
{
	if (n_c == 0)
		return ;
	free(n_c->file_path);
	free_str_ptr(n_c->argv);
	free(n_c);
}
