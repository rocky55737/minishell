/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:03:28 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:57 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_info			t_info;
typedef struct s_env			t_env;

typedef struct s_token			t_token;
typedef struct s_node_cmd		t_node_cmd;
typedef struct s_node_redirect	t_node_redirect;
typedef struct s_node_redirects	t_node_redirects;
typedef struct s_node_exec		t_node_exec;
typedef struct s_node_pipe		t_node_pipe;
typedef t_node_pipe				t_cmd_tree;
typedef struct s_ms_exec_data	t_ms_exec_data;

#endif
