/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:23:28 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/16 23:09:35 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_stack **stack_a)
{
	int		i;
	t_stack	*p;

	p = *stack_a;
	i = p->value;
	while (p)
	{
		if (i > p->value)
			i = p->value;
		p = p->next;
	}
	return (i);
}

static int	ft_indexing(t_stack **stack_a, int i, int k)
{
	int		index;
	t_stack	*p;

	p = *stack_a;
	index = 0;
	while (index < ft_stack_size(*stack_a))
	{
		if (p->value == i)
		{
			k = ft_stack_size(*stack_a);
			p->index = index++;
			i++;
		}
		if (p->next)
			p = p->next;
		else
			p = *stack_a;
		if (k-- == 0)
		{
			k = ft_stack_size(*stack_a);
			i++;
		}
	}
	return (0);
}

static int	ft_max_bit(t_stack **stack_a)
{
	t_stack	*p;
	int		i;
	int		j;

	j = 0;
	p = *stack_a;
	i = ft_stack_size(p);
	while (i)
	{
		i /= 2;
		j++;
	}
	return (j);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	t_stack	*p;

	i = -1;
	ft_indexing(stack_a, ft_get_min(stack_a), ft_stack_size(*stack_a));
	while (ft_check(stack_a) && ++i < ft_max_bit(stack_a))
	{
		p = *stack_a;
		j = ft_stack_size(p);
		while (j--)
		{
			p = *stack_a;
			if (p && !((p->index >> i) & 1))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		p = *stack_b;
		while (p)
		{
			pa(stack_a, stack_b);
			p = *stack_b;
		}
	}
}
