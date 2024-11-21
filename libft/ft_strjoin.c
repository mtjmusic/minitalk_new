/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:49:10 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/09 13:52:08 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	out_len;
	size_t	s1_len;
	size_t	s2_len;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	out_len = s1_len + s2_len;
	out = (char *)malloc((out_len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_bzero(out, out_len + 1);
	ft_strlcat(out, s1, s1_len + 1);
	ft_strlcat(out + s1_len, s2, s2_len + 1);
	return (out);
}
