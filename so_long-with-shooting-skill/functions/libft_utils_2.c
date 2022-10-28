/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:05:42 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:05:45 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**tabfree(char **tab)
{
	int	i;

	if (!tab)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static int	wordcount(const char *s, char c)
{
	int	q;
	int	i;

	q = 1;
	if (s[0] == ' ')
		q = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			q++;
		i++;
	}
	return (q);
}

static int	wordlen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wc;
	int		i[2];

	if (!s)
		return (NULL);
	i[0] = -1;
	wc = wordcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	while (++i[0] < wc)
	{
		tab[i[0]] = (char *)malloc(sizeof(char) * (wordlen(s, c) + 1));
		if (!tab[i[0]])
			return (tabfree(tab));
		while (*s == c)
			s++;
		i[1] = 0;
		while (*s != c && *s)
			tab[i[0]][i[1]++] = *s++;
		tab[i[0]][i[1]] = '\0';
	}
	tab[i[0]] = NULL;
	return (tab);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}
