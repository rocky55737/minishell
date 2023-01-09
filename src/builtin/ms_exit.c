/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:42 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 18:27:55 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_exit(char **av);

int	ms_exit(char **av)
{
	int		len;
	long	exit_code;

	ft_putstr_fd("exit\n", 2);
	exit_code = 0;
	if (av[1] == NULL)
		exit((int)exit_code % 256);
	if (!str_is_long_long(av[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	len = 0;
	while (av[len])
		len++;
	if (len > 2)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd("too many arguments\n", 2);
		return (1);
	}
	exit_code = ft_atol(av[1]);
	exit((int)exit_code % 256);
}
