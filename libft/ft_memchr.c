/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:24:46 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/10 10:59:43 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*out;
	unsigned char	to_find;

	out = (unsigned char *)s;
	to_find = (unsigned char)c;
	if (n < 1)
		return (NULL);
	while (n--)
	{
		if (*out == to_find)
			return (out);
		out++;
	}
	if (*out == 0 && to_find == 0 && n)
		return (out);
	return (NULL);
}

/* int main()
{
	char str[] = "bonjourno";
	char c = 'n';
	printf("%s\n%s\n", (char *)ft_memchr(str, c, 2), (char *)memchr(str, c, 2));
} */
