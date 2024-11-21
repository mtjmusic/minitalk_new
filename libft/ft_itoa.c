/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:43:05 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/11 10:06:57 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_handle_intmin(void)
{
	char	*out;

	out = (char *)malloc((12) * sizeof(char));
	if (!out)
		return (NULL);
	out[0] = '-';
	out[1] = '2';
	out[2] = '1';
	out[3] = '4';
	out[4] = '7';
	out[5] = '4';
	out[6] = '8';
	out[7] = '3';
	out[8] = '6';
	out[9] = '4';
	out[10] = '8';
	out[11] = '\0';
	return (out);
}

static int	ft_count_helper(int i, int count)
{
	if (i > 9)
		return (ft_count_helper(i / 10, count + 1));
	return (count + 1);
}

static int	ft_count(int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	return (ft_count_helper(i, count));
}

static void	ft_calculate(char *out, int count, int n)
{
	while (count-- > 1)
	{
		*out-- = (n % 10) + '0';
		n /= 10;
	}
	if (n)
		*out = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*out;
	char	*temp;
	int		count;

	count = ft_count(n);
	if (n == INT_MIN)
		return (ft_handle_intmin());
	if (n == 0)
		return (ft_strdup("0"));
	out = (char *)malloc((count + 1) * sizeof(char));
	if (!out)
		return (NULL);
	temp = out;
	if (n < 0)
	{
		*out++ = '-';
		n *= -1;
		count--;
	}
	out += count;
	*out-- = '\0';
	ft_calculate(out, count, n);
	return (temp);
}
