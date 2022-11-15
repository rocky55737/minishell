/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:53:19 by rhong             #+#    #+#             */
/*   Updated: 2022/11/15 17:05:53 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void	cd(char **argv)
{
	if (chdir(argv[1]) != 0)
	{
		strerror(errno);
		exit(-1);
	}
	// export(argv[1])
}
