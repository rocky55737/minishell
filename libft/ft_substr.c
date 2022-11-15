/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:53:16 by rhong             #+#    #+#             */
/*   Updated: 2022/04/09 14:49:28 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	cnt;
	size_t	s_len;

	sub_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_string)
		return (0);
	cnt = 0;
	s_len = my_strlen(s);
	while (cnt < len && start + cnt < s_len)
	{
		*(sub_string + cnt) = *(s + start + cnt);
		cnt++;
	}
	*(sub_string + cnt) = 0;
	return (sub_string);
}
