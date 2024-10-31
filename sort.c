/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:14:53 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/13 13:04:07 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*p;

	p = *stack_a;
	if (!ascending(p, 1, 2) && !ascending(p, 1, 3) && ascending(p, 2, 3))
		ra(stack_a);
	else if (!ascending(p, 1, 2))
	{
		if (!ascending(p, 1, 2))
		{
			sa(stack_a);
			p = *stack_a;
			if (!ascending(p, 2, 3))
				rra(stack_a);
		}
		else
			rra(stack_a);
	}
	else
	{
		rra(stack_a);
		p = *stack_a;
		if (!ascending(p, 1, 2))
			sa(stack_a);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	int		i;

	p = *stack_a;
	i = ft_get_min(stack_a);
	while (p && p->next)
		p = p->next;
	if (p->value == i)
		rra(stack_a);
	else
	{
		p = *stack_a;
		while (p->value != i)
		{
			ra(stack_a);
			p = *stack_a;
		}
	}
	if (!ft_check(stack_a))
		return ;
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*p;
	int		i;

	p = *stack_a;
	i = ft_get_min(stack_a);
	while (p && p->next)
		p = p->next;
	if (p->value == i)
		rra(stack_a);
	else
	{
		p = *stack_a;
		while (p->value != i)
		{
			ra(stack_a);
			p = *stack_a;
		}
	}
	pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_sort_stack(t_stack **stack_a)
{
	t_stack	*b;

	b = NULL;
	if (ft_stack_size(*stack_a) < 3)
		sa(stack_a);
	else if (ft_stack_size(*stack_a) <= 3)
		ft_sort_three(stack_a);
	else if (ft_stack_size(*stack_a) == 4)
		ft_sort_four(stack_a, &b);
	else if (ft_stack_size(*stack_a) == 5)
		ft_sort_five(stack_a, &b);
	else
		ft_radix(stack_a, &b);
	ft_free(NULL, &b);
	return ;
}
