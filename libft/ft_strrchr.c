/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:37:59 by rhong             #+#    #+#             */
/*   Updated: 2022/04/28 13:42:05 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	ind;
	int	ret;
	int	flag;

	ind = 0;
	flag = 0;
	while (s[ind] != 0)
	{
		if (s[ind] == c)
		{
			ret = ind;
			flag = 1;
		}
		ind++;
	}
	if (c == 0)
		return ((char *)&s[ind]);
	if (flag == 0)
		return (0);
	return ((char *)&s[ret]);
}
