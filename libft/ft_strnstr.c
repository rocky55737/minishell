/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:24:42 by rhong             #+#    #+#             */
/*   Updated: 2022/04/07 21:27:47 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	hay_cnt;
	size_t	needle_cnt;

	needle_len = my_strlen((char *)needle);
	if (needle_len == 0)
		return ((char *)haystack);
	hay_cnt = 0;
	while (haystack[hay_cnt] && hay_cnt < len)
	{
		needle_cnt = 0;
		if (haystack[hay_cnt] == needle[needle_cnt])
		{
			while (++needle_cnt < needle_len)
				if (needle[needle_cnt] != haystack[hay_cnt + needle_cnt])
					break ;
			if (needle_cnt == needle_len && needle_cnt + hay_cnt <= len)
				return ((char *)&haystack[hay_cnt]);
		}
		hay_cnt++;
	}
	return (0);
}
