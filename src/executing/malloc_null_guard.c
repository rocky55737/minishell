/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_null_guard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:35 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:12:42 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	malloc_null_guard(void *ptr)
{
	if (ptr == 0)
	{
		print_error("malloc error\n");
		exit(1);
	}
}
