/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:19 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 17:25:20 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	allow_control_character(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	suppress_control_character(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

int	ignore_signal(void)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR || \
	signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (ERROR);
	return (0);
}

void	handler_sigint(int signal)
{
	if (signal == SIGINT)
	{
		(void)signal;
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	init_signal(void)
{
	suppress_control_character();
	if (signal(SIGINT, handler_sigint) == SIG_ERR || \
	signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (ERROR);
	return (0);
}
