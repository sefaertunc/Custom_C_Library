/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:31:26 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/24 14:31:26 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_length(int n)
{
	size_t	i;

	i = 0;
	if (n < 0 || n == 0)
		++i;
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static void	fill_digits(char *str, int n, size_t len)
{
	size_t	i;

	i = 0;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[len - 1 - i] = (n % 10) + '0';
		n /= 10;
		++i;
	}
}

char	*ft_itoa(int n)
{
	size_t	len_s;
	char	*str;

	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	len_s = find_length(n);
	str = malloc(len_s + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	fill_digits(str, n, len_s);
	str[len_s] = '\0';
	return (str);
}
