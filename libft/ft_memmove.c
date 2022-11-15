/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:46:03 by rhong             #+#    #+#             */
/*   Updated: 2022/04/07 18:16:45 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	cnt;

	if (dst == src)
		return (dst);
	if (src > dst && (size_t)(src - dst) < n)
	{
		cnt = 0;
		while (cnt < n)
		{
			*(unsigned char *)(dst + cnt) = *(unsigned char *)(src + cnt);
			cnt++;
		}
	}
	else
	{
		while (n != 0)
		{
			*(unsigned char *)(dst + n - 1) = *(unsigned char *)(src + n - 1);
			n--;
		}
	}
	return (dst);
}
