/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:02:07 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/12 20:11:04 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const char *src, int n)
{
	char	*c_dest;
	char	*c_src;
	int		i;

	i = 0;
	c_dest = (char *) dest;
	c_src = (char *) src;
	if (dest || src)
	{
		while (i < n)
		{
			c_dest[i] = c_src[i];
			++i;
		}
	}
	return (dest);
}

int	ft_check(t_stack **stack_a)
{
	t_stack	*p;

	p = *stack_a;
	while (p && p->next)
	{
		if (ascending(p, 1, 2))
			p = p->next;
		else
			return (1);
	}
	return (0);
}

int	check_string(char **av)
{
	int		i;
	int		j;
	int		spaces;

	i = 0;
	j = 0;
	spaces = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				spaces++;
			j++;
		}
		if (j == spaces)
			return (1);
		i++;
	}
	return (0);
}
