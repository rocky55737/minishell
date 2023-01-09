/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:03:25 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 14:36:19 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Dependencies
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "data_type.h"
# include "libft.h"

/*
* Defines
*/
# define TRUE 1
# define FALSE 0
# define ERROR -1

# define COLOR_GRAY		"\x1b[30m"
# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_YELLOW_B	"\e[1;33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_PURPLE	"\e[0;35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_WHITE	"\x1b[37m"
# define COLOR_RESET	"\x1b[0m"

/*
* Functions
*/

/*
************** Main ****************
*/

// init.c
int					init(t_list **env_list, char **envp);

// shell_level.c
void				check_shlvl(t_env *node);

// signal1.c
int					init_signal(void);
void				allow_control_character(void);
void				suppress_control_character(void);
int					ignore_signal(void);
void				handler_sigint(int signal);

// signal2.c
void				heredoc_sigint(int signo);

/*
************** Parsing ***************
*/

// main_utils.c
int					check_argument(char argc, char **argv);
int					exit_by_eof(void);
int					is_not_only_whitespaces(char *input);

// parse_line.c
t_cmd_tree			*parse_line(char *line, t_list *env_list, \
t_list **tmp_files);

// ****** Lexical Analysis ********

// parse_utils1.c
int					ft_isspace(char c);
char				*ft_strjoin_free(char *s1, char *s2);
size_t				th_wordcount(char *str);
int					ft_strcmp(char *s1, char *s2);

// parse_utils2.c
t_token				*th_tokennew(int type, char *str);
t_env				*th_envnew(char *line);
void				print_error(char *message);
t_node_cmd			*find_file_path(t_list *tmp, int *cnt);

// tokenize.c
int					tokenize(char *line, t_list **token_list);

// tokenize_utils.c
void				token_type(char *token, int *type);
int					find_ending_letter(char *line, int *i);

// here_doc.c
t_list				*here_doc(t_list *token_list, int *error);

// here_doc_utils.c
void				h_infile_open(char *infile_path, char *delimiter);
char				*random_tmp_file(void);
char				*new_file_name(char *file_name);
char				*last_char_set(char *str, char set_char);

// ****** Syntax Analysis *******

// expand_env.c
int					expand_env(t_list *token_list, t_list *env_list);

// expand_env_utils.c
char				*get_env_variable(t_list *env_list, char *token_str);
char				*find_ending_quote(char *str, \
char *left_str, int *i, int *j);
void				found_dollar_sign(char **left_str, \
char *str, int *i, int *j);
int					check_tilde_expansion(t_token *curr_token, \
t_list *env_list);

// split_word.c
t_list				*split_word(char *str, t_list *curr_node);

// remove_quote.c
int					remove_quote(t_list *token_list);

// syntax_check.c
int					syntax_check(t_list *token_list);

// tree_parsing.c
t_node_pipe			*tree_parsing(t_list *token_list);

// free_list.c
void				free_token_list(t_list *token_list);

/*
************** Executing ***************
*/

t_list				*ms_exec_cmd(t_cmd_tree *cmd_input, t_list *env_list, \
t_list *tmp_files);
t_ms_exec_data		*ms_exec_cmd_init(t_cmd_tree *cmd_input, t_list *env_list);
int					ms_simple_command_expansion(t_node_exec *n_exec, \
t_ms_exec_data *data);
void				ms_command_search_and_execution(t_node_cmd *n_cmd, \
t_ms_exec_data *data);
void				ms_wait_all(pid_t *pids, int pid_cnt);
void				ms_set_back(int std_fd[2], t_list *tmp_files);
void				ms_free_data(t_ms_exec_data *data);
void				pipe_closing(t_ms_exec_data *data);
char				**env_list_to_str_ptr(t_list *env_list);
char				*find_cmd_path(char **env, char *cmd, int *builtin_flag);
void				cmd_exec_child(t_node_cmd *n_cmd, \
int builtin_flag, char **env, t_ms_exec_data *data);
void				close_pipes(int fd_arr[2]);
void				do_builtin_1(char **av, t_ms_exec_data *data, int flag);
void				do_builtin_2(char **av, t_ms_exec_data *data, int flag);
int					recursive_red(t_node_redirects *n_reds, \
int *in_file_fd, int *out_file_fd);
int					in_file_open(char *file_name);

void				free_str_ptr(char **str_ptr);
void				malloc_null_guard(void *ptr);

/*
************** Builtin ***************
*/

void				ms_echo(char **argv);
void				ms_pwd(void);
void				ms_env(char **av, t_ms_exec_data *data);
int					ms_exit(char **av);
int					ms_cd(char **argv, t_ms_exec_data *data);
int					ms_export(char **av, t_ms_exec_data *data);
void				ms_export_err(char *var_name);
int					ms_unset(char **av, t_ms_exec_data *data);

int					str_ptr_len(char **str_ptr);
int					str_is_long_long(char *str);
long				ft_atol(char *str);
int					can_be_name(char *var_name);
t_list				*find_env_by_name_in_list(t_list *env_list, char *name);

#endif
