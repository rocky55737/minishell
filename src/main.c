/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:31 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 20:57:47 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code;

static int	run_shell(char	*input, t_list **env_list)
{
	t_cmd_tree	*ast;
	t_list		*tmp_files;

	add_history(input);
	ast = parse_line(input, *env_list, &tmp_files);
	if (ast != NULL)
		ms_exec_cmd(ast, *env_list, tmp_files);
	return (0);
}

static int	minishell_loop(t_list **env_list)
{
	char	*input;
	int		shell_started;

	shell_started = FALSE;
	while (1)
	{
		if (shell_started == FALSE)
		{
			ft_putstr_fd(COLOR_YELLOW_B, STDERR_FILENO);
			shell_started = TRUE;
		}
		else if (g_exit_code == 0)
			ft_putstr_fd(COLOR_GREEN, STDERR_FILENO);
		else
			ft_putstr_fd(COLOR_RED, STDERR_FILENO);
		input = readline("minishell$ ");
		ft_putstr_fd(COLOR_RESET, STDERR_FILENO);
		if (input == NULL)
			return (exit_by_eof());
		else if (input[0] != '\0' && is_not_only_whitespaces(input))
			run_shell(input, env_list);
		free(input);
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env_list;

	if (check_argument(argc, argv))
	{
		if (init(&env_list, envp))
			g_exit_code = EXIT_FAILURE;
		minishell_loop(&env_list);
	}
	exit(g_exit_code);
}
