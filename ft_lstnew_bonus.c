/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:24:57 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/28 15:24:57 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*sample;

	sample = malloc(sizeof(t_list));
	if (!sample)
		return (NULL);
	sample->content = content;
	sample->next = NULL;
	return (sample);
}
