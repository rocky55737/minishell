/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:57:06 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 20:58:08 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_argument(char argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		return (1);
	print_error("invalid argument error\n");
	g_exit_code = 127;
	return (0);
}

int	exit_by_eof(void)
{
	ft_putstr_fd("\033[1A", STDERR_FILENO);
	ft_putstr_fd("\033[12C", STDERR_FILENO);
	ft_putstr_fd("exit\n", STDERR_FILENO);
	g_exit_code = EXIT_SUCCESS;
	allow_control_character();
	return (0);
}

int	is_not_only_whitespaces(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
