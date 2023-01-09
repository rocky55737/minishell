/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:51 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:13:50 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ms_cd(char **argv, t_ms_exec_data *data);
static char	*get_new_dir(char *dir, t_list *env_list);
static void	set_old_pwd(char *old_pwd, t_list *env_list);
static void	set_pwd(t_list *env_list);

int	ms_cd(char **argv, t_ms_exec_data *data)
{
	char	*new_dir;
	char	*old_dir;

	old_dir = getcwd(0, 0);
	if (old_dir == NULL)
	{
		perror("minishell: cd");
		return (1);
	}
	new_dir = get_new_dir(argv[1], data->env_list);
	if (chdir(new_dir) == -1)
	{
		free(new_dir);
		free(old_dir);
		perror("minishell: cd");
		return (1);
	}
	free(new_dir);
	set_old_pwd(old_dir, data->env_list);
	set_pwd(data->env_list);
	return (0);
}

static char	*get_new_dir(char *dir, t_list *env_list)
{
	char	*new_dir;

	if (!dir)
		new_dir = get_env_variable(env_list, "HOME");
	else if (!ft_strcmp(dir, "-"))
		new_dir = get_env_variable(env_list, "OLDPWD");
	else
		new_dir = ft_strdup(dir);
	malloc_null_guard(new_dir);
	return (new_dir);
}

static void	set_old_pwd(char *old_pwd, t_list *env_list)
{
	t_list	*parser;
	char	*tmp;

	parser = find_env_by_name_in_list(env_list, "OLDPWD");
	if (!parser)
		return ;
	free(((t_env *)parser->content)->value);
	((t_env *)parser->content)->value = old_pwd;
	free(((t_env *)parser->content)->initial_line);
	tmp = ft_strjoin("OLDPWD", "=");
	((t_env *)parser->content)->initial_line = ft_strjoin_free(tmp, old_pwd);
}

static void	set_pwd(t_list *env_list)
{
	t_list	*parser;
	char	*curr_dir;
	char	*tmp;

	parser = find_env_by_name_in_list(env_list, "PWD");
	if (!parser)
		return ;
	free(((t_env *)parser->content)->initial_line);
	free(((t_env *)parser->content)->value);
	curr_dir = getcwd(0, 0);
	if (curr_dir == NULL)
	{
		perror("minishell: cd");
		return ;
	}
	((t_env *)parser->content)->value = curr_dir;
	tmp = ft_strjoin("PWD", "=");
	((t_env *)parser->content)->initial_line = ft_strjoin_free(tmp, curr_dir);
}
