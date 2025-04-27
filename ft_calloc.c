/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:23:20 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/18 09:23:20 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*bz_ptr;
	size_t			total_size;
	size_t			i;

	i = 0;
	total_size = nmemb * size;
	if (size != 0 && nmemb != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (size == 0 || nmemb == 0)
		return (malloc(1));
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	bz_ptr = (unsigned char *)ptr;
	while (i < total_size)
	{
		bz_ptr[i] = 0;
		++i;
	}
	return (ptr);
}
