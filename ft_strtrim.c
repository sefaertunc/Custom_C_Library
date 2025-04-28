/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:30:44 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/24 14:30:44 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;
	size_t	total_length;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && char_is_in_set(s1[start], set))
		++start;
	end = ft_strlen(s1);
	while (end > start && char_is_in_set(s1[end - 1], set))
		--end;
	total_length = end - start;
	trimmed_str = malloc(total_length + 1);
	if (!trimmed_str)
		return (0);
	ft_memcpy(trimmed_str, s1 + start, total_length);
	trimmed_str[total_length] = '\0';
	return (trimmed_str);
}
