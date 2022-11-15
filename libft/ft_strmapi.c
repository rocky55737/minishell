/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:28 by rhong             #+#    #+#             */
/*   Updated: 2022/04/09 17:26:57 by rhong            ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped_str;
	size_t	len;
	size_t	cnt;

	len = my_strlen(s);
	mapped_str = (char *)malloc(len + 1);
	if (!mapped_str)
		return (0);
	cnt = 0;
	while (cnt < len)
	{
		mapped_str[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	mapped_str[cnt] = 0;
	return (mapped_str);
}
