/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:24:48 by rhong             #+#    #+#             */
/*   Updated: 2022/04/07 18:52:19 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;
	char	*ss1;
	char	*ss2;

	if (n == 0)
		return (0);
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	count = 0;
	while (count < n && ss1[count] == ss2[count])
		count++;
	if (count == n)
		return ((unsigned char)ss1[count - 1] - (unsigned char)ss2[count - 1]);
	return ((unsigned char)ss1[count] - (unsigned char)ss2[count]);
}
