/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:23:38 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/18 09:23:38 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*ptr;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	ptr = malloc(s_len + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
