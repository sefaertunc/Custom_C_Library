/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sefaertnc <sefaertnc@student.42vienna.com> :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:31:16 by sefaertnc         #+#    #+#             */
/*   Updated: 2025/04/24 14:31:16 by sefaertnc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_array_length(char const *s, char c)
{
	size_t	is_start;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	is_start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!is_start)
			{
				is_start = 1;
				++count;
			}
		}
		else
			is_start = 0;
		++i;
	}
	return (count);
}

static char	*make_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_substr(s, 0, i));
}

static void	free_split(char **arr, size_t length)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (i < length)
		free(arr[i++]);
	free(arr);
}

static int	fill_split(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	is_start;

	i = 0;
	j = 0;
	is_start = 0;
	while (s[i])
	{
		if (s[i] != c && !is_start)
		{
			arr[j] = make_word(s + i, c);
			if (!arr[j])
				return (free_split(arr, j), 0);
			++j;
			is_start = 1;
		}
		else if (s[i] == c)
			is_start = 0;
		++i;
	}
	arr[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	total_words;
	char	**arr;

	if (!s)
		return (0);
	total_words = get_array_length(s, c);
	arr = malloc((total_words + 1) * sizeof(char *));
	if (!arr)
		return (0);
	if (!fill_split(arr, s, c))
		return (0);
	return (arr);
}
