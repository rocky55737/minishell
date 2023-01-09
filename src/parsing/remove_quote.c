/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:16 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:17 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_double_quote_index(char *str, \
int *quote_index, int *quote_count, int *i)
{
	quote_index[*i] = TRUE;
	(*quote_count)++;
	(*i)++;
	while (str[*i] && str[*i] != '\"')
		(*i)++;
	quote_index[*i] = TRUE;
	(*quote_count)++;
}

static void	find_single_quote_index(char *str, \
int *quote_index, int *quote_count, int *i)
{
	quote_index[*i] = TRUE;
	(*quote_count)++;
	(*i)++;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	quote_index[*i] = TRUE;
	(*quote_count)++;
}

static char	*check_and_copy_str(char *str, \
int *quote_index, int *quote_count)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = ft_calloc((ft_strlen(str) - *quote_count + 1), sizeof(char));
	while (str[i])
	{
		if (quote_index[i] == FALSE)
			result[j++] = str[i];
		i++;
	}
	return (result);
}

static char	*quote_removed_str(char *str)
{
	int		i;
	int		*quote_index;
	int		quote_count;
	char	*result;

	i = 0;
	quote_count = 0;
	quote_index = ft_calloc(ft_strlen(str), sizeof(int));
	while (str[i])
	{
		if (str[i] == '\'')
			find_single_quote_index(str, quote_index, &quote_count, &i);
		else if (str[i] == '\"')
			find_double_quote_index(str, quote_index, &quote_count, &i);
		if (str[i] == '\0')
			break ;
		i++;
	}
	result = check_and_copy_str(str, quote_index, &quote_count);
	free(quote_index);
	return (result);
}

int	remove_quote(t_list *token_list)
{
	t_list	*curr_node;
	t_token	*token;
	char	*refined_str;

	curr_node = token_list;
	while (curr_node)
	{
		token = (t_token *)(curr_node->content);
		if ((token->type == T_WORD) && \
		(ft_strchr(token->str, '\'') != 0 || \
		ft_strchr(token->str, '\"') != 0))
		{
			refined_str = quote_removed_str(token->str);
			free(token->str);
			token->str = refined_str;
			token->type = T_WORD;
		}
		curr_node = curr_node->next;
	}
	return (0);
}
