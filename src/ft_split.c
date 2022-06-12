/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:59:16 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/04 12:04:03 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = -1;
	count = 0;
	flag = 0;
	while (s[++i] != '\0')
	{
		if (flag == 1 && s[i] == c)
			flag = 0;
		else if (flag == 0 && s[i] != c)
		{
			flag = 1;
			count++;
		}
	}
	return (count);
}

int	ft_cl(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		len;
	int		count;
	int		i;

	if (s == 0)
		return (NULL);
	len = ft_count(s, c);
	table = (char **)malloc (sizeof(*table) * (len + 1));
	if (!table)
		return (NULL);
	i = 0;
	while (len--)
	{
		count = 0;
		while (*s == c && *s != '\0')
			s++;
		table[i] = ft_substr ((const char *)s, 0, ft_cl((const char *)s, c));
		s = s + ft_cl (s, c);
		i++;
	}
	table[i] = 0;
	return (table);
}
