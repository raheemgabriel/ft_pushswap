/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:08:16 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/12 13:34:56 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_b;
	if (p)
	{
		tmp = p->next;
		p->next = *stack_a;
		*stack_a = p;
		*stack_b = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p)
	{
		tmp = p->next;
		p->next = *stack_b;
		*stack_b = p;
		*stack_a = tmp;
		write(1, "pb\n", 3);
	}
}

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		while ((*stack_a)->next)
			(*stack_a) = (*stack_a)->next;
		(*stack_a)->next = p;
		p->next = NULL;
		*stack_a = tmp;
		write(1, "ra\n", 3);
	}
}

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		while (p->next->next)
			p = p->next;
		tmp = p->next;
		p->next = NULL;
		tmp->next = (*stack_a);
		*stack_a = tmp;
		write(1, "rra\n", 4);
	}
}

void	sa(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*p;

	p = *stack_a;
	if (p && p->next)
	{
		tmp = p->next;
		p->next = p->next->next;
		tmp->next = p;
		*stack_a = tmp;
		write(1, "sa\n", 3);
	}
}
