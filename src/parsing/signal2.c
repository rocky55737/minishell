/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:21:10 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 18:07:48 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_sigint(int signo)
{
	static int	fd;

	if (signo != SIGINT)
	{
		fd = signo;
		return ;
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	close(fd);
	exit(1);
}
