/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:45 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:37:29 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_set_back(int std_fd[2], t_list *tmp_files)
{
	t_list	*tmp;
	t_list	*parser;

	dup2(std_fd[0], 0);
	dup2(std_fd[1], 1);
	close(std_fd[0]);
	close(std_fd[1]);
	init_signal();
	parser = tmp_files;
	while (parser)
	{
		tmp = parser;
		parser = parser->next;
		unlink((char *)tmp->content);
		free(tmp->content);
		free(tmp);
	}
}
