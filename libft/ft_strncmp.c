/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:20:05 by rhong             #+#    #+#             */
/*   Updated: 2022/04/05 21:40:15 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int	count;

	if (n == 0)
		return (0);
	count = 0;
	while (count < n && s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	if (count == n)
		return ((unsigned char)s1[count - 1] - (unsigned char)s2[count - 1]);
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
