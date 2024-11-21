/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:25:05 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/04 17:11:58 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*out;
	char	*in;
	size_t	size_dest;
	size_t	size_src;

	out = dst;
	in = (char *)src;
	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dest >= size)
		return (size + size_src);
	while (*out)
		out++;
	while (*in && size_dest + 1 < size)
	{
		*out++ = *in++;
		size--;
	}
	*out = '\0';
	return (size_dest + size_src);
}
