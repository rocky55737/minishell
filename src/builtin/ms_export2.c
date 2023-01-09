/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:37 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:13:16 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_export_err(char *var_name)
{
	ft_putstr_fd("minishell: export: \'", 2);
	ft_putstr_fd(var_name, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	free(var_name);
}
