/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:56:24 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/12 19:17:59 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*fstrjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	result = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!result)
		return (NULL);
	if (s1 && s2)
	{
		ft_memcpy(result, s1, strlen(s1));
		ft_memcpy(result + strlen(s1), s2, strlen(s2));
	}
	result[strlen(s1) + strlen(s2)] = '\0';
	return (result);
}

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = num;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **a, t_stack *new)
{
	t_stack	*p;

	p = *a;
	if (!(*a))
	{
		(*a) = new;
		return ;
	}
	while (p->next)
		(p) = (p)->next;
	(p)->next = new;
}

size_t	strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
