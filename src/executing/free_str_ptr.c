/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:09:32 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:12:33 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_ptr(char **str_ptr)
{
	int	cnt;

	cnt = 0;
	while (str_ptr[cnt])
	{
		free(str_ptr[cnt]);
		cnt++;
	}
	free(str_ptr);
}
