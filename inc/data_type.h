/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:03:16 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:44:26 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

# include "libft.h"
# include "typedef.h"
/*
* global_variable
*/

extern int	g_exit_code;

/*
Env
*/
struct s_env
{
	char	*initial_line;
	char	*key;
	char	*value;
};

/*
 * Token
 */

# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_REDIRECT 3
# define T_HEREDOC 4

struct s_token
{
	int		type;
	char	*str;
};

/*
AST
*/
struct s_node_cmd
{
	char	*file_path;
	char	**argv;
};

struct s_node_redirect
{
	int		redirect_type;
	char	*file_name;
};

struct s_node_redirects
{
	t_node_redirect			*n_red;
	struct s_node_redirects	*n_reds;
};

struct s_node_exec
{
	t_node_redirects	*n_reds;
	t_node_cmd			*n_cmd;
};

struct s_node_pipe
{
	t_node_exec			*n_exec;
	struct s_node_pipe	*n_pipe;
};

struct s_ms_exec_data
{
	t_cmd_tree	*c_tree;
	t_list		*env_list;
	pid_t		*pids;
	int			pipes_fd[2][2];
	int			std_fd[2];
	int			cmd_num;
	int			fork_cnt;
};

#endif
