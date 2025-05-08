/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:21:14 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/05/08 09:42:14 by mertunc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == uc)
			return ((char *)s);
		++s;
	}
	if (*s == uc)
		return ((char *)s);
	return (0);
}
