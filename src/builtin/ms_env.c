/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:44 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:14:17 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_env(char **av, t_ms_exec_data *data)
{
	int		len;
	t_list	*tmp;

	len = str_ptr_len(av);
	if (len > 1)
	{
		print_error("env with no options/arguments required\n");
		exit(1);
	}
	tmp = data->env_list;
	while (tmp)
	{
		if (((t_env *)(tmp->content))->value && \
		*((t_env *)(tmp->content))->value)
			printf("%s\n", ((t_env *)(tmp->content))->initial_line);
		tmp = tmp->next;
	}
	exit(0);
}
