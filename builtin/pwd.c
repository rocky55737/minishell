/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:26:34 by rhong             #+#    #+#             */
/*   Updated: 2022/11/15 16:47:13 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"
#include "../libft/libft.h"
#include <stdio.h>

void	pwd(char **env)
{
	int	cnt;

	cnt = 0;
	while (ft_strncmp("PWD=", env[cnt], 4) != 0)
		cnt++;
	printf("%s\n", &(env[cnt][4]));
}
