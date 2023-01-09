/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:48 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 16:56:20 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ms_echo(char **argv);
static int	is_option(char *str);

void	ms_echo(char **argv)
{
	int	n_op;
	int	argv_cnt;

	n_op = 0;
	argv_cnt = 1;
	while (argv[argv_cnt] && is_option(argv[argv_cnt]))
	{
		n_op++;
		argv_cnt++;
	}
	while (argv[argv_cnt])
	{
		printf("%s", argv[argv_cnt]);
		if (argv[argv_cnt + 1])
			printf(" ");
		argv_cnt++;
	}
	if (!n_op)
		printf("\n");
	exit(0);
}

static int	is_option(char *str)
{
	int	cnt;

	if (str[0] != '-')
		return (0);
	cnt = 1;
	while (str[cnt])
	{
		if (str[cnt] != 'n')
			return (0);
		cnt++;
	}
	return (1);
}
