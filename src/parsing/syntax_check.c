/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:23 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 16:27:54 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe_syntax(t_list *curr_node, t_list *before_node)
{
	if (before_node == NULL)
	{
		print_error("syntax error near unexpected token `|\'\n");
		return (ERROR);
	}
	else if ((curr_node->next != NULL && \
	((t_token *)curr_node->next->content)->type == T_PIPE))
	{
		print_error("syntax error near unexpected token `|\'\n");
		return (ERROR);
	}
	return (0);
}

static int	check_redir_syntax(t_list *curr_node)
{
	if (((t_token *)curr_node->next->content)->type == T_PIPE)
	{
		if (curr_node->next->next == NULL)
			print_error("syntax error near unexpected token `newline\'\n");
		else
			print_error("syntax error near unexpected token `|\'\n");
		return (ERROR);
	}
	else if (((t_token *)curr_node->next->content)->type == T_REDIRECT || \
	((t_token *)curr_node->next->content)->type == T_HEREDOC)
	{
		print_error("syntax error near unexpected token `");
		ft_putstr_fd(((t_token *)curr_node->next->content)->str, 2);
		ft_putstr_fd("\'\n", 2);
		return (ERROR);
	}
	return (0);
}

int	syntax_check(t_list *token_list)
{
	t_list	*before_node;

	before_node = NULL;
	while (token_list)
	{
		if (((t_token *)token_list->content)->type == T_PIPE)
		{
			if (check_pipe_syntax(token_list, before_node) == ERROR)
				return (ERROR);
		}
		else if (((t_token *)token_list->content)->type == T_REDIRECT || \
		((t_token *)token_list->content)->type == T_HEREDOC)
		{
			if (check_redir_syntax(token_list))
				return (ERROR);
		}
		before_node = token_list;
		token_list = token_list->next;
	}
	return (0);
}
