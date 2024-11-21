/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:25:16 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/11 10:21:15 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*out;
	char	*in;
	size_t	len_in;

	out = (char *)big;
	in = (char *)little;
	len_in = ft_strlen(in);
	if (*in == 0)
		return ((char *)big);
	while (len && *out && len_in <= len)
	{
		if (!ft_strncmp(out, in, len_in))
			return (out);
		out++;
		len--;
	}
	return (NULL);
}

/* int main()
{
char str[] = "lorem ipsum dolor sit amat";
char little[] = "dolor";
printf("%s\n%s\n", (char *)ft_strnstr(str, little,  15), 
(char *)strnstr(str, little, 15));

} */
