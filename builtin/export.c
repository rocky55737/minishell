/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:52:50 by rhong             #+#    #+#             */
/*   Updated: 2022/11/15 17:05:57 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

char	**export(char **av, char **env)
{
	int	av_cnt;

	av_cnt = 1;
	while (av[av_cnt])
	{
		// analysis
		// mod_env = get_env av[av_cnt]
		// if (mod_env == -1)
		// 	env = str_ptr_cat av[av_cnt]
		// else
		// 	mod_env = strdup av[av_cnt]
		av_cnt++;
	}
}