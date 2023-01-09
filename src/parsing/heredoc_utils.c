/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:11:03 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 09:48:06 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	h_infile_open(char *infile_path, char *delimiter)
{
	int		fd;
	char	*buffer;

	fd = open(infile_path, O_CREAT | O_WRONLY, 0644);
	heredoc_sigint(fd);
	buffer = readline("> ");
	while (buffer && ft_strcmp(delimiter, buffer) != 0)
	{
		write(fd, buffer, ft_strlen(buffer));
		write(fd, "\n", ft_strlen("\n"));
		free(buffer);
		buffer = readline("> ");
	}
	free(buffer);
	close(fd);
	exit(0);
}

char	*random_tmp_file(void)
{
	char		*file_name;
	struct stat	st_stat;

	file_name = ft_strdup("/tmp/.heredoc0");
	malloc_null_guard(file_name);
	st_stat.st_mode = 0;
	stat(file_name, &st_stat);
	while (st_stat.st_mode != 0)
	{
		file_name = new_file_name(file_name);
		st_stat.st_mode = 0;
		stat(file_name, &st_stat);
	}
	return (file_name);
}

char	*new_file_name(char *file_name)
{
	char		last_c;

	last_c = file_name[ft_strlen(file_name) - 1];
	if (last_c == '9')
		last_c = 0;
	else
		last_c++;
	if (last_c == 0)
		file_name = ft_strjoin_free(file_name, "0");
	else
		file_name = last_char_set(file_name, last_c);
	return (file_name);
}

char	*last_char_set(char *str, char set_char)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	if (cnt == 0)
		return (0);
	else
		str[cnt - 1] = set_char;
	return (str);
}
