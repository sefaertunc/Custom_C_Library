/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:31:46 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/24 14:31:46 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	i;
	size_t	len_s;

	if (!s || !f)
		return (0);
	len_s = ft_strlen(s);
	new_s = malloc(len_s + 1);
	if (!new_s)
		return (0);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		++i;
	}
	new_s[i] = '\0';
	return (new_s);
}
