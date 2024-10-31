/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:23:48 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/16 23:29:42 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst,
	const char *src, size_t dstsize)
{
	size_t	i;
	int		len;

	len = strlen(src);
	i = 0;
	if (dstsize)
	{
		while ((src[i]) && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

size_t	safe_mlc(char **toc_v, int pos, size_t buff)
{
	int	i;

	toc_v[pos] = malloc(buff);
	i = 0;
	if (NULL == toc_v[pos])
	{
		while (i < pos)
			free(toc_v[i++]);
		free(toc_v);
		return (1);
	}
	return (0);
}

size_t	fill(char **toc_v, char *s, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_mlc(toc_v, i, len + 1))
				return (1);
			ft_strlcpy(toc_v[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	size_t	tokens;
	char	**toc_v;

	tokens = tocnt(s, c);
	toc_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == toc_v)
		return (NULL);
	toc_v[tokens] = NULL;
	if (fill(toc_v, s, c))
		return (NULL);
	return (toc_v);
}
