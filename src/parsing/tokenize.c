/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:27 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:23:44 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_new_token_node(t_list **token_list, \
char *str, int type)
{
	t_list	*new_list_node;
	t_token	*new_token_node;

	new_token_node = th_tokennew(type, str);
	malloc_null_guard(new_token_node);
	new_list_node = ft_lstnew(new_token_node);
	malloc_null_guard(new_list_node);
	ft_lstadd_back(token_list, new_list_node);
}

int	line_to_tokens(char *line, t_list **token_list)
{
	int		i;
	int		start_i;
	int		type;
	char	*str;

	i = 0;
	type = 0;
	while (line[i] != '\0')
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		start_i = i;
		if (find_ending_letter(line, &i) == ERROR)
			return (ERROR);
		if (i == start_i)
			return (0);
		str = ft_substr(line, start_i, i - start_i);
		malloc_null_guard(str);
		token_type(str, &type);
		add_new_token_node(token_list, str, type);
	}
	return (0);
}

void	add_pipe_node(t_list **token_list)
{
	t_token	*new_token_node;
	t_list	*new_list_node;
	char	*token_str;

	token_str = ft_strdup("|");
	malloc_null_guard(token_str);
	new_token_node = th_tokennew(T_PIPE, token_str);
	malloc_null_guard(new_token_node);
	new_list_node = ft_lstnew(new_token_node);
	malloc_null_guard(new_list_node);
	ft_lstadd_back(token_list, new_list_node);
}

int	tokenize(char *line, t_list **token_list)
{
	if (line_to_tokens(line, token_list))
		return (ERROR);
	add_pipe_node(token_list);
	return (0);
}
