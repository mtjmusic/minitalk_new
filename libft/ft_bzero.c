/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:24:25 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/10 10:48:19 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*out;

	out = s;
	while (n--)
	{
		*out++ = '\0';
	}
}
/* int main()
{
	char normal1[] = "2147483647";
	char normal2[] = "2147483647";
	char empty1[] = "";
	char empty2[] = "";


	ft_bzero(normal1, 3);
	ft_bzero(normal2, 3);
	ft_bzero(empty1, ft_strlen(empty1));
	ft_bzero(empty2, ft_strlen(empty2));

	char *normal1p = normal1;
	char *normal2p = normal2;
	char *empty1p = empty1;
	char *empty2p = empty2;


	printf("org: %s\tft_bzero: %s\n\n", normal1p, normal2p);
	printf("org: %s\tft_bzero: %s\n\n", empty1p, empty2p);
	
} */