/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:25:08 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/11 10:14:59 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	char	*out;
	char	*in;

	size_src = ft_strlen(src);
	out = dst;
	in = (char *)src;
	if (size > 0)
	{
		while (*in && size-- > 1)
			*out++ = *in++;
		*out = '\0';
	}
	return (size_src);
}
