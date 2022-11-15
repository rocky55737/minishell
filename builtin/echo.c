/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:24:59 by rhong             #+#    #+#             */
/*   Updated: 2022/11/15 15:48:40 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"
#include <stdio.h>

void		echo(char **argv);
static int	is_option(char *str);

void	echo(char **argv)
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
		printf("%s\n", argv[argv_cnt]);
		argv_cnt++;
	}
	if (!n_op)
		printf("\n");
}

static int	is_option(char *str)
{
	int	cnt;

	if (str[0] == '-')
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
