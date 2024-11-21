/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:24:52 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/04 17:09:51 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*out;
	const unsigned char	*in;

	out = (unsigned char *)dest;
	in = (const unsigned char *)src;
	if (dest == src || n == 0)
		return (dest);
	while (n--)
		*out++ = *in++;
	return (dest);
}
