/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:11:06 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 18:05:58 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexical_analysis(char *line, t_list **token_list)
{
	if (tokenize(line, token_list) == ERROR)
		return (ERROR);
	return (0);
}

static int	syntax_analysis(t_list **token_list, t_list *env_list, \
t_list **tmp_files)
{
	int	error;

	error = FALSE;
	if (syntax_check(*token_list) == ERROR)
	{
		g_exit_code = 258;
		return (ERROR);
	}
	*tmp_files = here_doc(*token_list, &error);
	if (error == TRUE)
		return (ERROR);
	expand_env(*token_list, env_list);
	remove_quote(*token_list);
	return (0);
}

t_cmd_tree	*parse_line(char *line, t_list *env_list, t_list **tmp_files)
{
	t_cmd_tree	*ast;
	t_list		*token_list;

	ast = NULL;
	token_list = NULL;
	if (lexical_analysis(line, &token_list) != ERROR)
		if (syntax_analysis(&token_list, env_list, tmp_files) != ERROR)
			ast = tree_parsing(token_list);
	free_token_list(token_list);
	return (ast);
}
