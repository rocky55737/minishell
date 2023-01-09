/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:22 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:22 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*relink_token_nodes(t_list *curr_node, char *word)
{
	t_list	*new_node;
	t_list	*tmp_node;
	t_token	*new_token;

	tmp_node = curr_node->next;
	new_token = th_tokennew(T_WORD, word);
	new_node = ft_lstnew(new_token);
	new_node->next = tmp_node;
	curr_node->next = new_node;
	curr_node = curr_node->next;
	return (curr_node);
}

static t_list	*save_nonspaces(t_list *curr_node, \
char *word, int word_count, int word_number)
{
	malloc_null_guard(word);
	((t_token *)(curr_node->content))->str = word;
	((t_token *)(curr_node->content))->type = T_WORD;
	if (word_count < word_number)
		curr_node = relink_token_nodes(curr_node, word);
	return (curr_node);
}

t_list	*split_word(char *str, t_list *curr_node)
{
	int		i;
	int		j;
	int		word_number;
	int		word_count;

	i = 0;
	word_count = 0;
	word_number = th_wordcount(str);
	if (word_number < 2)
		return (curr_node);
	while (str[i])
	{
		j = i;
		while (str[i] && ft_isspace(str[i]) == 0)
			i++;
		word_count++;
		if (i > j)
			curr_node = save_nonspaces(curr_node, \
			ft_substr(str, j, i - j), word_count, word_number);
		while (str[i] && ft_isspace(str[i]))
			i++;
	}
	free(str);
	return (curr_node);
}
