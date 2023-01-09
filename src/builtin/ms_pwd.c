/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:34 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:14:52 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		exit(0);
	}
	perror("minishell: pwd: ");
	exit(1);
}
