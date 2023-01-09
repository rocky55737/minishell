/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:09 by taehooki          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:10 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' \
		|| c == '\f' || c == '\r');
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && s2)
	{
		s1 = ft_strdup(s2);
		return (s1);
	}
	else if (!s2)
		return (s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	result = (char *)malloc(i + j + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, i);
	ft_memcpy(result + i, s2, j + 1);
	free(s1);
	return (result);
}

size_t	th_wordcount(char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (str)
	{
		while (str[i])
		{
			while (str[i] && ft_isspace(str[i]) == 0)
				i++;
			count++;
			if (str[i] == '\0')
				break ;
			while (ft_isspace(str[i]) != 0)
				i++;
		}
	}
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	count;

	count = 0;
	while (s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
