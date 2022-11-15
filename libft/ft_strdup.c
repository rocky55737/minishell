/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:43:58 by rhong             #+#    #+#             */
/*   Updated: 2022/04/07 18:20:13 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*duped_str;

	src_len = 0;
	while (src[src_len])
		src_len++;
	duped_str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (duped_str == 0)
		return (0);
	src_len = 0;
	while (src[src_len])
	{
		duped_str[src_len] = src[src_len];
		src_len++;
	}
	duped_str[src_len] = 0;
	return (duped_str);
}
