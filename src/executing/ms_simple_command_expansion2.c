/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_simple_command_expansion2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:49 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:13:47 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	recursive_red(t_node_redirects *n_reds, \
int *in_file_fd, int *out_file_fd);
int	out_file_open(int open_f, char *file_name);

int	recursive_red(t_node_redirects *n_reds, \
int *in_file_fd, int *out_file_fd)
{
	if (*in_file_fd == ERROR || *out_file_fd == ERROR)
		return (ERROR);
	if (n_reds == 0)
		return (0);
	if (n_reds->n_red->redirect_type == 0)
	{
		if (*in_file_fd != 0)
			close(*in_file_fd);
		*in_file_fd = in_file_open(n_reds->n_red->file_name);
		if (*in_file_fd == ERROR)
			return (ERROR);
	}
	else
	{
		if (*out_file_fd != 0)
			close(*out_file_fd);
		*out_file_fd = out_file_open(n_reds->n_red->redirect_type, \
		n_reds->n_red->file_name);
		if (*out_file_fd == ERROR)
			return (ERROR);
	}
	if (n_reds->n_reds == 0)
		return (0);
	return (recursive_red(n_reds->n_reds, in_file_fd, out_file_fd));
}

int	out_file_open(int open_f, char *file_name)
{
	int	out_file_fd;

	if (open_f == 1)
		out_file_fd = open(file_name, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	else
		out_file_fd = open(file_name, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (out_file_fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": ", 2);
		perror(0);
	}
	return (out_file_fd);
}
