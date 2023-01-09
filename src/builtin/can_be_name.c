/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_be_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:08:01 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:13:20 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	can_be_name(char *var_name)
{
	int	cnt;

	cnt = 0;
	if (!ft_isalpha(var_name[cnt]) && var_name[cnt] != '_')
		return (0);
	cnt = 1;
	while (var_name[cnt])
	{
		if (!ft_isalnum(var_name[cnt]) && var_name[cnt] != '_')
			return (0);
		cnt++;
	}
	return (1);
}
