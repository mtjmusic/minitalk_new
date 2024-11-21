/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:25:19 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/04 17:14:30 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;
	char	to_find;

	to_find = (unsigned char)c;
	out = (char *)s;
	while (*out)
		out++;
	while (out >= s)
	{
		if (*out == to_find)
			return (out);
		out--;
	}
	return (NULL);
}
