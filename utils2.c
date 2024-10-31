/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:39:21 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/16 23:12:52 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	ascending(t_stack *stack, int target1, int target2)
{
	int		num1;
	int		num2;
	t_stack	*tmp;

	num1 = 0;
	num2 = 0;
	tmp = stack;
	while (--target1 && tmp->next)
		tmp = tmp->next;
	num1 = tmp->value;
	tmp = stack;
	while (--target2 && tmp->next)
		tmp = tmp->next;
	num2 = tmp->value;
	return (num1 < num2);
}

int	ft_atoi(const char *str, int *overflow)
{
	int		i;
	long	nb;
	int		is_negative;

	is_negative = 0;
	nb = 0;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		is_negative = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (str[i] - 48) + (10 * nb);
		if (nb > ((long)2147483647 + (is_negative == 1)))
			*overflow = 1;
		i++;
	}
	if (is_negative == 1)
		nb = nb * -1;
	return (nb);
}

int	check_dups(t_stack **a)
{
	t_stack	*p;
	t_stack	*p2;

	p = *a;
	p2 = *a;
	while (p)
	{
		p2 = p->next;
		while (p2)
		{
			if (p->value == p2->value)
			{
				return (1);
			}
			p2 = p2->next;
		}
		p = p->next;
	}
	return (0);
}

size_t	tocnt(char *s, char c)
{
	size_t	tokens;
	bool	in;

	tokens = 0;
	while (*s)
	{
		in = false;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!in)
			{
				tokens++;
				in = true;
			}
			s++;
		}
	}
	return (tokens);
}
