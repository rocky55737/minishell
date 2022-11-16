/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:33:54 by rhong             #+#    #+#             */
/*   Updated: 2022/11/16 18:49:00 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_node_pipe
{
	t_node_exec	*n_cmd;
	t_node_pipe	*n_pipe;
}	t_node_pipe;

typedef struct s_node_exec
{
	t_node_redirect	*n_red;
	t_node_cmd		*n_cmd;
}	t_node_exec;

typedef struct s_node_redirect
{
	t_node_redirect	*n_red_left;
	t_node_redirect	*n_red_right;
	int				redirect_type;
	char			*file_name;
}	t_node_redirect;

typedef struct s_cmd
{
	char	*file_path;
	char	**argv;
}	t_node_cmd;

#endif