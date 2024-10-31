/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:43:56 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/16 23:12:00 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*p;
	t_stack		*tmp;

	if (stack_a && *stack_a)
	{
		p = *stack_a;
		while (p)
		{
			tmp = p->next;
			free (p);
			p = tmp;
		}
	}
	if (stack_b && *stack_b)
	{
		p = *stack_b;
		while (p)
		{
			tmp = p->next;
			free (p);
			p = tmp;
		}
	}
}

void	ft_check_if_sorted(t_stack **stack_a)
{
	t_stack	*p;

	p = *stack_a;
	while (p && p->next && p->value < p->next->value)
		p = p->next;
	if (!p->next)
	{
		ft_free(stack_a, NULL);
		exit(0);
	}
	return ;
}

char	*join_strs(char **av, int ac)
{
	int		i;
	char	*res;
	char	*tmp;

	res = calloc(1, (sizeof(char)));
	if (!res)
		return (write(2, "Error\n", 6), NULL);
	i = 0;
	while (i < ac - 1)
	{
		tmp = res;
		res = fstrjoin(res, " ");
		free(tmp);
		if (!res)
			return (write(2, "Error\n", 6), NULL);
		tmp = res;
		res = fstrjoin(res, av[i + 1]);
		free(tmp);
		if (!res)
			return (write(2, "Error\n", 6), NULL);
		i++;
	}
	return (res);
}

bool	check_validity(char **sres)
{
	int	i;
	int	j;

	i = 0;
	if (!sres || !sres[i])
		return (write(2, "Error\n", 6), false);
	while (sres[i] != NULL)
	{
		j = 0;
		while (sres[i][j])
		{
			if ((sres[i][j] == '-' || sres[i][j] == '+'))
			{
				if (j != 0 || !ft_isnum(sres[i][j + 1]))
					return (write(2, "Error\n", 7), false);
			}
			else if (!ft_isnum(sres[i][j]))
				return (write(2, "Error\n", 7), false);
			j++;
		}
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		overflow;
	char	*res;
	char	**sres;

	a = NULL;
	if (ac < 2)
		return (1);
	if (check_string(av) == 1)
		return (write(2, "Error\n", 6), 1);
	res = join_strs(av, ac);
	sres = ft_split(res, ' ');
	if (!check_validity(sres))
		return (free(res), free_strs(sres), 1);
	i = 0;
	overflow = 0;
	while (sres[i])
		add_back(&a, new_node(ft_atoi(sres[i++], &overflow)));
	(free(res), free_strs(sres));
	if (overflow == 1 || check_dups(&a))
		return (ft_free(&a, NULL), write(2, "Error\n", 7), 1);
	ft_check_if_sorted(&a);
	ft_sort_stack(&a);
	return (ft_free(&a, NULL), 0);
}
