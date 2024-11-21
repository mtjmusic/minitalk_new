/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:24:55 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/04 17:10:04 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*out;
	const char	*in;

	out = dest;
	in = src;
	if (dest == src)
		return (dest);
	if (out < in)
	{
		while (n--)
			*out++ = *in++;
	}
	else
	{
		out += n;
		in += n;
		while (n--)
			*--out = *--in;
	}
	return (dest);
}
