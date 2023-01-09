/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_long_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:26 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/27 18:28:09 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long long			check_sign(const char *str);
static unsigned long long	my_atoi(const char *str);
static int					str_is_number(char *str);
int							str_is_long_long(char *str);

static long long	check_sign(const char *str)
{
	unsigned long long		ind;
	long long				sign;

	ind = 0;
	sign = 1;
	if (str[ind] == '-')
		sign = -1;
	return (sign);
}

static unsigned long long	my_atoi(const char *str)
{
	unsigned long long	result;
	unsigned long long	ind;

	ind = 0;
	result = 0;
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		result = result * 10;
		if (str[ind] > '0')
			result = result + (str[ind] - '0');
		ind++;
	}
	return (result);
}

static int	str_is_number(char *str)
{
	int	cnt;

	cnt = 0;
	if (str[cnt] == '-')
		cnt++;
	if (!str[cnt])
		return (0);
	while (str[cnt])
	{
		if (!ft_isdigit(str[cnt]))
			return (0);
		cnt++;
	}
	return (1);
}

int	str_is_long_long(char *str)
{
	unsigned long long	data;
	long long			sign;

	if (!str_is_number(str))
		return (0);
	sign = check_sign(str);
	if (sign == -1)
		str++;
	data = my_atoi(str);
	if (sign == 1 && data > 9223372036854775807ul)
		return (0);
	else if (sign == -1 && data > 9223372036854775808ul)
		return (0);
	return (1);
}
