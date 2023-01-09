/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:25 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 21:07:47 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_type(char *token, int *type)
{
	if (ft_strcmp(token, "|") == 0)
		*type = T_PIPE;
	else if (ft_strcmp(token, "<<") == 0)
		*type = T_HEREDOC;
	else if (ft_strcmp(token, "<") == 0 || \
	ft_strcmp(token, ">") == 0 || \
	ft_strcmp(token, ">>") == 0)
		*type = T_REDIRECT;
	else
		*type = T_WORD;
}

static int	find_ending_word(char *line, int *i)
{
	while (line[*i] != '\0' && ft_isspace(line[*i]) == FALSE && \
	!(line[*i] == '<' || line[*i] == '>' || line[*i] == '|'))
	{
		if (line[*i] == '\'')
		{
			(*i)++;
			while (line[*i] && line[*i] != '\'')
				(*i)++;
			if (line[*i] == '\0')
				return (ERROR);
		}
		else if (line[*i] == '\"')
		{
			(*i)++;
			while (line[*i] && line[*i] != '\"')
				(*i)++;
			if (line[*i] == '\0')
				return (ERROR);
		}
		(*i)++;
	}
	return (0);
}

int	find_ending_letter(char *line, int *i)
{
	if (!ft_strncmp(line + *i, "<<", 2) || !ft_strncmp(line + *i, ">>", 2))
	{
		*i = (*i) + 2;
		return (0);
	}
	else if (line[*i] == '<' || line[*i] == '>' || line[*i] == '|')
	{
		(*i)++;
		return (0);
	}
	if (find_ending_word(line, i) == ERROR)
	{
		print_error("matching quote not found\n");
		return (ERROR);
	}
	return (0);
}
