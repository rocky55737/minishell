/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:27 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/28 13:23:25 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_builtin_1(char **av, t_ms_exec_data *data, int flag)
{
	if (flag == 1)
		ms_echo(av);
	if (flag == 2)
		ms_pwd();
	if (flag == 3)
		ms_env(av, data);
	if (flag == 4)
		exit(ms_cd(av, data));
	if (flag == 5)
		exit(ms_export(av, data));
	if (flag == 6)
		exit(ms_unset(av, data));
	if (flag == 7)
		exit(ms_exit(av));
}
