/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:11:00 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 13:44:41 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_tmp_files(t_list *tmp_files)
{
	t_list	*tmp;
	t_list	*parser;

	parser = tmp_files;
	while (parser)
	{
		tmp = parser;
		parser = parser->next;
		unlink((char *)tmp->content);
		free(tmp->content);
		free(tmp);
	}
}

int	check_here_doc(char **file_name, t_list *tmp_files, \
char *delimiter, int *error)
{
	pid_t	pid;
	int		stat;

	stat = 0;
	*file_name = random_tmp_file();
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, heredoc_sigint);
		h_infile_open(*file_name, delimiter);
	}
	waitpid(pid, &stat, 0);
	signal(SIGINT, handler_sigint);
	if (((stat >> 8) & 0x000000ff) != 0)
	{
		g_exit_code = (stat >> 8) & 0x000000ff;
		ft_lstadd_back(&tmp_files, ft_lstnew(*file_name));
		delete_tmp_files(tmp_files);
		*error = TRUE;
		return (ERROR);
	}
	return (0);
}

t_list	*here_doc(t_list *token_list, int *error)
{
	t_list	*tmp_files;
	t_list	*curr_node;
	char	*file_name;

	tmp_files = NULL;
	curr_node = token_list;
	while (curr_node)
	{
		if (((t_token *)curr_node->content)->type == T_HEREDOC)
		{
			if (check_here_doc(&file_name, tmp_files, \
			((t_token *)curr_node->next->content)->str, error))
				break ;
			free(((t_token *)curr_node->content)->str);
			((t_token *)curr_node->content)->str = ft_strdup("<");
			malloc_null_guard(((t_token *)curr_node->content)->str);
			((t_token *)curr_node->content)->type = T_REDIRECT;
			free(((t_token *)curr_node->next->content)->str);
			((t_token *)curr_node->next->content)->str = file_name;
			((t_token *)curr_node->next->content)->type = T_WORD;
			ft_lstadd_back(&tmp_files, ft_lstnew(ft_strdup(file_name)));
		}
		curr_node = curr_node->next;
	}
	return (tmp_files);
}
