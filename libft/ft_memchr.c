/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:44:16 by rhong             #+#    #+#             */
/*   Updated: 2022/04/05 21:29:54 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (*(char *)(s + cnt) == c)
			return ((void *)(s + cnt));
		cnt++;
	}
	return (0);
}
