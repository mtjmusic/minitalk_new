/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:44:55 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/10 18:34:35 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	len;

	len = ft_strlen(s1);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, len + 1);
	return (out);
}
