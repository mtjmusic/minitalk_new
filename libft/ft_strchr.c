/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:25:02 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/04 17:11:14 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*out;
	char	to_find;

	to_find = (unsigned char)c;
	out = (char *)s;
	while (*out)
	{
		if (*out == to_find)
			return (out);
		out++;
	}
	if (*out == to_find)
		return (out);
	return (NULL);
}
