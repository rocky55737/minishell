/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:39:57 by rhong             #+#    #+#             */
/*   Updated: 2022/04/09 17:16:26 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_len(long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*do_itoa(char *s, size_t c, size_t l, long long n)
{
	size_t	len;

	len = l + 1;
	if (c == 0)
		len--;
	s[len] = 0;
	if (n == 0)
		s[0] = '0';
	while (c < len && n > 0)
	{
		s[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	num;
	size_t		cnt;
	size_t		len;

	num = n;
	cnt = 0;
	len = itoa_len(num);
	if (num < 0)
	{
		cnt++;
		num *= -1;
	}
	str = (char *)malloc(sizeof(char) * (len + cnt + 1));
	if (!str)
		return (0);
	if (cnt == 1)
		str[0] = '-';
	do_itoa(str, cnt, len, num);
	return (str);
}
