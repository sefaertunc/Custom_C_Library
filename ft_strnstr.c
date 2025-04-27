/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:22:33 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/23 09:38:00 by mertunc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*s;
	char	*t;
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		s = (char *)&str[i];
		t = (char *)to_find;
		j = 0;
		while (s[j] && t[j] && s[j] == t[j]
			&& (i + j) < len)
			j++;
		if (!t[j])
			return (s);
		++i;
	}
	return (0);
}
