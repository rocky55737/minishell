/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:49:38 by rhong             #+#    #+#             */
/*   Updated: 2022/04/09 17:12:38 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_charset(char c, char const *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (charset[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static int	trimed_strlen(char const *src, char const *charset)
{
	int	len;
	int	offset_left;
	int	offset_right;

	offset_left = 0;
	offset_right = -1;
	len = 0;
	while (is_char_in_charset(src[offset_left], charset))
		offset_left++;
	while (src[offset_left + len])
		len++;
	while (is_char_in_charset(src[offset_left + len + offset_right], charset))
		offset_right--;
	if (len + offset_right + 1 < 0)
		return (0);
	return (len + offset_right + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_str;
	int		trimed_cnt;
	int		s1_cnt;
	int		trimed_len;

	trimed_len = trimed_strlen(s1, set);
	trimed_str = (char *)malloc(sizeof(char) * (trimed_len + 1));
	if (trimed_str == 0)
		return (0);
	trimed_cnt = 0;
	s1_cnt = 0;
	while (s1[s1_cnt] && is_char_in_charset(s1[s1_cnt], set))
			s1_cnt++;
	while (s1[s1_cnt + trimed_cnt] && trimed_cnt < trimed_len)
	{
		trimed_str[trimed_cnt] = s1[s1_cnt + trimed_cnt];
		trimed_cnt++;
	}
	trimed_str[trimed_cnt] = 0;
	return (trimed_str);
}
