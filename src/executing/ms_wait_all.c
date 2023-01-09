/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_wait_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:51 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 14:54:59 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_exit_code(int pid_cnt, int stat);

void	ms_wait_all(pid_t *pids, int pid_cnt)
{
	int	cnt;
	int	stat;
	int	other_stat;

	if (pid_cnt == 0)
		return ;
	waitpid(pids[pid_cnt - 1], &stat, 0);
	cnt = 0;
	while (cnt < pid_cnt - 1)
	{
		waitpid(pids[cnt], &other_stat, 0);
		if ((other_stat & 0177) != 0177 && (other_stat & 0177) != 0)
		{
			if ((other_stat & 127) == 3)
				ft_putstr_fd("Quit: 3", 2);
			ft_putchar_fd('\n', 2);
		}
		cnt++;
	}
	set_exit_code(pid_cnt, stat);
}

static void	set_exit_code(int pid_cnt, int stat)
{
	if (pid_cnt)
	{
		if ((stat & 0177) != 0177 && (stat & 0177) != 0)
		{
			g_exit_code = (stat & 127) + 128;
			if ((stat & 127) == 3)
				ft_putstr_fd("Quit: 3", 2);
			ft_putchar_fd('\n', 2);
		}
		else
			g_exit_code = stat >> 8;
	}
}
