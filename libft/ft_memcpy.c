/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:32:02 by rhong             #+#    #+#             */
/*   Updated: 2022/04/28 14:21:55 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == src)
		return (dst);
	while (n != 0)
	{
		*(unsigned char *)(dst + n - 1) = *(unsigned char *)(src + n - 1);
		n--;
	}
	return (dst);
}
