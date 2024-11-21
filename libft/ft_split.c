/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matej <matej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:33:00 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/11 11:17:34 by matej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int		words;
	char	*str;

	str = (char *)s;
	words = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			words++;
		while (*str && *str != c)
			str++;
	}
	return (words);
}

static void	ft_free_split(char **split, int i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
}

static char	*ft_strdup_len(const char *str, int len)
{
	char	*word;
	char	*temp;
	char	*s;

	s = (char *)str;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	temp = word;
	while (len--)
		*temp++ = *s++;
	*temp = '\0';
	return (word);
}

char	**ft_split_split(const char *s, char c, char **out)
{
	int		len;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] != c && s[len])
				len++;
			out[i] = ft_strdup_len(s, len);
			if (!out[i])
				return (ft_free_split(out, i), NULL);
			s += len - 1;
			i++;
		}
		if (*s)
			s++;
	}
	out[i] = NULL;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;

	if (!s)
		return (NULL);
	out = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	out = ft_split_split(s, c, out);
	return (out);
}
