/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matej <matej@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:59:02 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/11 10:34:03 by matej            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	char	*beg_s1;
	char	*end_s1;
	size_t	out_len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	beg_s1 = (char *)s1;
	end_s1 = (char *)s1 + ft_strlen(s1) - 1;
	while (*beg_s1 && ft_strchr(set, *beg_s1))
		beg_s1++;
	while (end_s1 >= beg_s1 && ft_strchr(set, *end_s1))
		end_s1--;
	out_len = end_s1 - beg_s1 + 1;
	out = (char *)malloc((out_len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, beg_s1, out_len + 1);
	return (out);
}
