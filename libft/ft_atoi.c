/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:24:20 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/10 11:07:47 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int	out;
	int	sign;

	out = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		out = out * 10 + *str % '0';
		str++;
	}
	return (out * sign);
}
/* int main()
{
	char *intmax = "2147483647";
	char *intmin = "-2147483648";
	char *intminmin = "-2147483855";
	char *minus = "-1024";
	char *plus = "1024";
	char *zero = "0";
	char *plus1 = "+123";
	char *plusminus = "+-123";
	char *minusplus = "-+123";
	char *plusplus = "++123";
	char *minusminus = "--123";
	char *space = "      -123";
	char *space2 = "-  123";
	char *space3 = "-  123   123";
	char *character = "123a123";

	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", intmax, ft_atoi(intmax), atoi(intmax));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", intmin, ft_atoi(intmin), atoi(intmin));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", intminmin, ft_atoi(intminmin), atoi(intminmin));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", minus, ft_atoi(minus), atoi(minus));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", plus, ft_atoi(plus), atoi(plus));
	printf("org: %s\tft_atoi: %d\tatoi: 
	%d\n\n", zero, ft_atoi(zero), atoi(zero));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", plus1, ft_atoi(plus1), atoi(plus1));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", plusminus, ft_atoi(plusminus), atoi(plusminus));
	printf("org: %s\tft_atoi: %d\tatoi
	: %d\n\n", minusplus, ft_atoi(minusplus), atoi(minusplus));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", plusplus, ft_atoi(plusplus), atoi(plusplus));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", minusminus, ft_atoi(minusminus), atoi(minusminus));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", space, ft_atoi(space), atoi(space));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", space2, ft_atoi(space2), atoi(space2));
	printf("org: %s\tft_atoi: %d\tatoi: 
	%d\n\n", space3, ft_atoi(space3), atoi(space3));
	printf("org: %s\tft_atoi: %d\tatoi:
	 %d\n\n", character, ft_atoi(character), atoi(character));

} */