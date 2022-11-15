/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:09:43 by rhong             #+#    #+#             */
/*   Updated: 2022/04/07 18:26:33 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n)
{
	return (n < 0);
}

static void	print_num(int n, int fd)
{
	char	letter;

	letter = n % 10 + 48;
	if (n >= 10)
	{
		print_num(n / 10, fd);
	}
	write(fd, &letter, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (is_negative(n))
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	print_num(n, fd);
}
