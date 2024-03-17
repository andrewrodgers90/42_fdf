/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:52:03 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/04 13:25:29 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return ((void *)0);
	if (ft_strlen(s) < start)
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return ((void *)0);
		return (sub);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return ((void *)0);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	**ft_freeall(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		if (i == 0)
		{
			break ;
		}
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_allocatewords(char **arr, char const *s, char sep)
{
	char const	*temp;
	size_t		i;

	temp = s;
	i = 0;
	while (*temp)
	{
		while (*s == sep)
			s++;
		temp = s;
		while (*temp && *temp != sep)
			temp++;
		if (*temp == sep || *temp == '\0')
		{
			if (temp > s)
			{
				arr[i] = ft_substr(s, 0, temp - s);
				if (arr[i] == NULL)
					return (ft_freeall(arr, i));
				i++;
			}
			s = temp;
		}
	}
	return (arr);
}

int	ft_wordcount(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
		{
			s++;
		}
		if (*s)
		{
			word_count++;
		}
		while (*s && *s != sep)
		{
			s++;
		}
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	size = ft_wordcount(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
	{
		return (0);
	}
	new[size] = NULL;
	return (ft_allocatewords(new, s, c));
}
