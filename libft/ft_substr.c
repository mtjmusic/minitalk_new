/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:34:17 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/05 12:30:08 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	s_len;
	size_t	out_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	out_len = s_len - start;
	if (len < out_len)
		out_len = len;
	out = (char *)malloc((out_len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, out_len + 1);
	return (out);
}
