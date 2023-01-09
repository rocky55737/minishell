/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:28 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 17:51:50 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_node_pipe		*make_pipe_node(t_list *token_list);
static t_node_exec		*make_exec_node(t_list *token_list);
static t_node_redirects	*make_reds_node(t_list *token_list);
static t_node_cmd		*make_cmd_node(t_list *token_list, int cnt);

t_node_pipe	*tree_parsing(t_list *token_list)
{
	t_list		*parser;
	t_node_pipe	*ret;

	parser = token_list;
	ret = make_pipe_node(parser);
	return (ret);
}

static t_node_pipe	*make_pipe_node(t_list *token_list)
{
	t_node_pipe	*ret;

	if (token_list == 0)
		return (0);
	ret = (t_node_pipe *)malloc(sizeof(t_node_pipe));
	malloc_null_guard(ret);
	ret->n_exec = make_exec_node(token_list);
	while (((t_token *)(token_list->content))->type != T_PIPE)
		token_list = token_list->next;
	token_list = token_list->next;
	if (token_list)
		ret->n_pipe = make_pipe_node(token_list);
	else
		ret->n_pipe = 0;
	return (ret);
}

static t_node_exec	*make_exec_node(t_list *token_list)
{
	t_node_exec	*ret;

	ret = (t_node_exec *)malloc(sizeof(t_node_exec));
	malloc_null_guard(ret);
	ret->n_reds = make_reds_node(token_list);
	if (token_list)
		ret->n_cmd = make_cmd_node(token_list, 0);
	else
		ret->n_cmd = 0;
	return (ret);
}

static t_node_redirects	*make_reds_node(t_list *token_list)
{
	t_node_redirects	*ret;

	if (!token_list)
		return (0);
	while (((t_token *)token_list->content)->type != T_PIPE && \
	((t_token *)token_list->content)->type != T_REDIRECT)
		token_list = token_list->next;
	if (((t_token *)token_list->content)->type == T_PIPE)
		return (0);
	ret = (t_node_redirects *)malloc(sizeof(t_node_redirects));
	malloc_null_guard(ret);
	ret->n_red = (t_node_redirect *)malloc(sizeof(t_node_redirect));
	malloc_null_guard(ret->n_red);
	if (ft_strcmp(((t_token *)(token_list->content))->str, "<") == 0)
		ret->n_red->redirect_type = 0;
	else if (ft_strcmp(((t_token *)(token_list->content))->str, ">") == 0)
		ret->n_red->redirect_type = 1;
	else
		ret->n_red->redirect_type = 2;
	ret->n_red->file_name = \
	ft_strdup(((t_token *)(token_list->next->content))->str);
	malloc_null_guard(ret->n_red->file_name);
	ret->n_reds = make_reds_node(token_list->next->next);
	return (ret);
}

static t_node_cmd	*make_cmd_node(t_list *token_list, int cnt)
{
	t_node_cmd	*ret;

	ret = find_file_path(token_list, &cnt);
	if (ret == NULL)
		return (0);
	ret->argv = (char **)malloc(sizeof(char *) * (cnt + 1));
	malloc_null_guard(ret->argv);
	cnt = 0;
	while (((t_token *)(token_list->content))->type != T_PIPE)
	{
		if (((t_token *)(token_list->content))->type == T_REDIRECT)
			token_list = token_list->next->next;
		else
		{
			ret->argv[cnt] = ft_strdup(((t_token *)(token_list->content))->str);
			malloc_null_guard(ret->argv[cnt]);
			cnt++;
			token_list = token_list->next;
		}
	}
	ret->argv[cnt] = 0;
	return (ret);
}
