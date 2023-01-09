/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:31 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 18:27:15 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*find_cmd_path(char **env, char *cmd, int *builtin_flag);
static int	cmd_is_builtin(char *cmd);
static char	*find_cmd_in_path_env(char **env, char *cmd);
static char	**set_all_paths(char **env, char *cmd);

char	*find_cmd_path(char **env, char *cmd, int *builtin_flag)
{
	struct stat	st_stat;
	int			flag_num;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	flag_num = cmd_is_builtin(cmd);
	if (flag_num)
	{
		*builtin_flag = flag_num;
		return (cmd);
	}
	st_stat.st_mode = 0;
	stat(cmd, &st_stat);
	if ((st_stat.st_mode & 0000100) && ((0170000 & st_stat.st_mode) != 0040000))
		return (cmd);
	return (find_cmd_in_path_env(env, cmd));
}

static int	cmd_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (2);
	if (ft_strcmp(cmd, "env") == 0)
		return (3);
	if (ft_strcmp(cmd, "cd") == 0)
		return (4);
	if (ft_strcmp(cmd, "export") == 0)
		return (5);
	if (ft_strcmp(cmd, "unset") == 0)
		return (6);
	if (ft_strcmp(cmd, "exit") == 0)
		return (7);
	return (0);
}

static char	*find_cmd_in_path_env(char **env, char *cmd)
{
	int			cnt;
	char		**all_paths;
	char		*buffer;
	struct stat	st_stat;

	all_paths = set_all_paths(env, cmd);
	cnt = 0;
	ft_memset(&st_stat, 0, sizeof(st_stat));
	while (all_paths && all_paths[cnt])
	{
		stat(all_paths[cnt], &st_stat);
		if ((st_stat.st_mode & 0000100) && \
		((0170000 & st_stat.st_mode) != 0040000))
			break ;
		cnt++;
	}
	if (!all_paths || !all_paths[cnt])
		buffer = ft_strdup(cmd);
	else
		buffer = ft_strdup(all_paths[cnt]);
	if (all_paths)
		free_str_ptr(all_paths);
	return (buffer);
}

static char	**set_all_paths(char **env, char *cmd)
{
	int		cnt;
	char	**all_paths;
	char	*buffer;

	cnt = 0;
	while (env[cnt] && ft_strncmp("PATH=", env[cnt], 5) != 0)
		cnt++;
	if (!env[cnt])
		return (0);
	all_paths = ft_split(&(env[cnt][5]), ':');
	cnt = 0;
	while (all_paths[cnt])
	{
		buffer = ft_strjoin_free(all_paths[cnt], "/");
		all_paths[cnt] = ft_strjoin_free(buffer, cmd);
		cnt++;
	}
	return (all_paths);
}
