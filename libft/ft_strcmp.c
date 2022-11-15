/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:35:12 by rhong             #+#    #+#             */
/*   Updated: 2022/09/16 18:43:21 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	count;

	count = 0;
	while (s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
