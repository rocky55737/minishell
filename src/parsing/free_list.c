/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:10:58 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:01 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token_list(t_list *token_list)
{
	t_list	*curr_node;
	t_list	*tmp_node;

	curr_node = token_list;
	while (curr_node)
	{
		free(((t_token *)curr_node->content)->str);
		tmp_node = curr_node;
		free(tmp_node->content);
		curr_node = curr_node->next;
		free(tmp_node);
	}
}
