/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:05:00 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 10:44:46 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_variable(t_list *env_list, char *token_str)
{
	char	*expanded_str;
	t_list	*curr_env;

	curr_env = env_list;
	while (curr_env)
	{
		if (!ft_strcmp(token_str, ((t_env *)(curr_env->content))->key))
		{
			expanded_str = ft_strdup(((t_env *)(curr_env->content))->value);
			return (expanded_str);
		}
		curr_env = curr_env->next;
	}
	expanded_str = ft_strdup("");
	return (expanded_str);
}

char	*find_ending_quote(char *str, char *left_str, int *i, int *j)
{
	char	*new_str;
	char	*quoted_str;

	new_str = NULL;
	(*i)++;
	while (str[*i] != '\'')
		(*i)++;
	(*i)++;
	quoted_str = ft_substr(str, *j, *i - *j);
	new_str = ft_strjoin_free(left_str, quoted_str);
	malloc_null_guard(new_str);
	free(quoted_str);
	*j = *i;
	return (new_str);
}

void	found_dollar_sign(char **left_str, char *str, int *i, int *j)
{
	if (*left_str == NULL && *i != 0)
	{
		*left_str = ft_substr(str, 0, *i);
		malloc_null_guard(*left_str);
	}
	(*i)++;
	*j = *i;
	if (str[*i] == '?')
	{
		(*i)++;
		return ;
	}
	if (str[*i] && (ft_isalpha(str[*i]) || str[*i] == '_'))
	{
		(*i)++;
		while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
			(*i)++;
	}
}

int	check_tilde_expansion(t_token *curr_token, t_list *env_list)
{
	char	*home;

	if (curr_token->type == T_WORD && \
	ft_strcmp(curr_token->str, "~") == 0)
	{
		home = get_env_variable(env_list, "HOME");
		free(curr_token->str);
		curr_token->str = home;
		return (TRUE);
	}
	else
		return (FALSE);
}
