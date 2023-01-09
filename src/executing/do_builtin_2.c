/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:28 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 18:27:06 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_builtin_2(char **av, t_ms_exec_data *data, int flag)
{
	data->fork_cnt--;
	if (flag == 4)
		g_exit_code = ms_cd(av, data);
	if (flag == 5)
		g_exit_code = ms_export(av, data);
	if (flag == 6)
		g_exit_code = ms_unset(av, data);
	if (flag == 7)
		g_exit_code = ms_exit(av);
}
