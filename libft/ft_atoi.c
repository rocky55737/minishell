/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:41:07 by rhong             #+#    #+#             */
/*   Updated: 2022/04/28 14:17:34 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (is_space(str[ind]))
		ind++;
	sign = 1;
	if (str[ind] == '-')
		sign = -1;
	return (sign);
}

static size_t	my_atoi(const char *str)
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

int	ft_atoi(const char *str)
{
	size_t		result;
	long long	sign;

	sign = check_sign(str);
	result = my_atoi(remove_space_plus_minus(str));
	if (sign == 1 && result > 2147483647)
		return (-1);
	else if (sign == -1 && result > 2147483648)
		return (0);
	return (sign * result);
}
