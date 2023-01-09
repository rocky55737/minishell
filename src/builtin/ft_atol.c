/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:07:55 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 18:13:41 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			is_space(char c);
static const char	*remove_space_plus_minus(const char *str);
static long long	check_sign(const char *str);
static size_t		my_atol(const char *str);
long				ft_atol(char *str);

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static const char	*remove_space_plus_minus(const char *str)
{
	size_t	ind;

	ind = 0;
	while (is_space(str[ind]))
		ind++;
	if (str[ind] == '+' || str[ind] == '-')
		ind++;
	return ((const char *)&str[ind]);
}

static long long	check_sign(const char *str)
{
	size_t		ind;
	long long	sign;

	ind = 0;
	sign = 1;
	if (str[ind] == '-')
		sign = -1;
	return (sign);
}

static size_t	my_atol(const char *str)
{
	size_t	result;
	size_t	ind;

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

long	ft_atol(char *str)
{
	unsigned long long	result;
	long long			sign;

	sign = check_sign(str);
	result = my_atol(remove_space_plus_minus(str));
	if (sign == 1 && result > 9223372036854775807ul)
		return (-1);
	else if (sign == -1 && result > 9223372036854775808ul)
		return (0);
	return (sign * (long)result);
}
