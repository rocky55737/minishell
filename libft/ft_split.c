/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:37:57 by rhong             #+#    #+#             */
/*   Updated: 2022/04/28 15:59:03 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_size(char const *s, char c)
{
	size_t	size;
	size_t	s_cnt;

	s_cnt = 0;
	size = 0;
	while (s[s_cnt])
	{
		if (s[s_cnt] == c)
			while (s[s_cnt] == c && s[s_cnt])
				s_cnt++;
		else
		{
			size++;
			while (s[s_cnt] != c && s[s_cnt])
				s_cnt++;
		}
	}
	return (size);
}

static size_t	str_c_cpy(char *dest, char const *src, char c)
{
	size_t	index;

	index = 0;
	while (src[index] && src[index] != c)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (index);
}

static size_t	my_str_c_len(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static int	check_alloc(char **s, size_t index)
{
	int	cnt;

	cnt = (int)index;
	if (!s[cnt])
	{
		while (cnt > -1)
		{
			free(s[cnt]);
			s[cnt] = 0;
			cnt--;
		}
		s = 0;
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	s_cnt;
	size_t	split_cnt;
	size_t	len;

	splitted = (char **)malloc(sizeof(char *) * (split_size(s, c) + 1));
	if (!splitted)
		return (0);
	split_cnt = 0;
	s_cnt = 0;
	while (s[s_cnt] && split_cnt < split_size(s, c))
	{
		len = my_str_c_len(&s[s_cnt], c);
		if (len > 0)
		{
			splitted[split_cnt] = (char *)malloc(sizeof(char) * (len) + 1);
			if (!check_alloc(splitted, split_cnt))
				return (0);
			s_cnt = s_cnt + str_c_cpy(splitted[split_cnt], &s[s_cnt], c);
			split_cnt++;
		}
		s_cnt++;
	}
	splitted[split_cnt] = 0;
	return (splitted);
}
