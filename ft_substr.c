/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mertunc <mertunc@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:48:25 by mertunc           #+#    #+#             */
/*   Updated: 2025/04/23 14:48:29 by mertunc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (!s || str_len <= (size_t)start)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
