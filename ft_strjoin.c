/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:47:34 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/24 10:47:34 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_length;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(total_length + 1);
	if (!new_str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		++j;
	}
	new_str[total_length] = '\0';
	return (new_str);
}
