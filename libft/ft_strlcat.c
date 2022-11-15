/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:04:50 by rhong             #+#    #+#             */
/*   Updated: 2022/04/28 14:23:24 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	src_index;
	size_t	dest_len;
	size_t	src_len;

	dest_len = my_strlen(dest);
	src_len = my_strlen(src);
	if (size < dest_len + 1)
		return (size + src_len);
	src_index = 0;
	while (src_index < size - dest_len - 1 && src[src_index] != '\0')
	{
		dest[dest_len + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_len + src_index] = '\0';
	return (dest_len + src_len);
}
