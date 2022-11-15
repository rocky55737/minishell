/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhong <rhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:17:43 by rhong             #+#    #+#             */
/*   Updated: 2022/04/28 14:23:47 by rhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	len;
	size_t	counter;

	counter = 0;
	len = my_strlen(src);
	while (counter < len && counter < size - 1 && size != 0)
	{
		dest[counter] = src[counter];
		counter++;
	}
	if (size > 0)
		dest[counter] = '\0';
	return (len);
}
