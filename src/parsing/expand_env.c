/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:10:53 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 10:46:18 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	convert_join(char **left_str, \
char *probable_env, t_list *env)
{
	char	*expanded_str;

	malloc_null_guard(probable_env);
	if (probable_env[0] == '?')
		expanded_str = ft_itoa(g_exit_code);
	else
		expanded_str = get_env_variable(env, probable_env);
	malloc_null_guard(expanded_str);
	free(probable_env);
	*left_str = ft_strjoin_free(*left_str, expanded_str);
	malloc_null_guard(*left_str);
	free(expanded_str);
}

static char	*join_nondollar(char *str, char *left_str, int i, int j)
{
	char	*right_str;

	right_str = ft_substr(str, j, i - j);
	malloc_null_guard(right_str);
	left_str = ft_strjoin_free(left_str, right_str);
	malloc_null_guard(left_str);
	free(right_str);
	return (left_str);
}

static char	*check_str(char *str, int j, t_list *env)
{
	char	*left_str;
	int		i;

	i = 0;
	left_str = NULL;
	while (str[i])
	{
		if (str[i] == '\'')
			left_str = find_ending_quote(str, left_str, &i, &j);
		else if (str[i] == '$')
		{
			left_str = join_nondollar(str, left_str, i, j);
			found_dollar_sign(&left_str, str, &i, &j);
			convert_join(&left_str, ft_substr(str, j, i - j), env);
			j = i;
		}
		else
			i++;
	}
	left_str = join_nondollar(str, left_str, i, j);
	return (left_str);
}

char	*check_and_expand(char *str, t_list *env)
{
	int		j;
	char	*left_str;

	j = 0;
	left_str = check_str(str, j, env);
	malloc_null_guard(left_str);
	return (left_str);
}

int	expand_env(t_list *token_list, t_list *env_list)
{
	char	*expanded_str;
	t_token	*curr_token;

	while (token_list != NULL)
	{
		curr_token = (t_token *)token_list->content;
		if (check_tilde_expansion(curr_token, env_list))
			;
		else if (curr_token->type == T_WORD && \
		ft_strchr(curr_token->str, '$'))
		{
			expanded_str = check_and_expand(curr_token->str, env_list);
			free(curr_token->str);
			curr_token->str = expanded_str;
			token_list = split_word(expanded_str, token_list);
		}
		token_list = token_list->next;
	}
	return (0);
}
