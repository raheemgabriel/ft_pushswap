/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abgabrie <abgabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:37:41 by abgabrie          #+#    #+#             */
/*   Updated: 2024/10/16 23:29:42 by abgabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				index;
	int				value;
}				t_stack;

int			ft_get_min(t_stack **stack_a);
char		*fstrjoin(char const *s1, char const *s2);
size_t		strlen(const char *s);
size_t		ft_strlcpy(char *dst,
				const char *src, size_t dstsize);
size_t		safe_mlc(char **toc_v, int pos, size_t buff);
size_t		fill(char **toc_v, char *s, char c);
size_t		tocnt(char *s, char c);
char		**ft_split(char *s, char c);
int			ft_isnum(int c);
void		free_strs(char **strs);
void		add_back(t_stack **a, t_stack *new);
t_stack		*new_node(int num);
int			check_dups(t_stack **a);
int			ft_check(t_stack **stack_a);
int			ft_atoi(const char *str, int *overflow);
int			ascending(t_stack *stack, int target1, int target2);
int			ft_stack_size(t_stack *stack_a);
int			check_string(char **av);
void		*ft_memcpy(void *dest, const char *src, int n);
void		ft_free(t_stack **stack_a, t_stack **stack_b);
void		ft_check_if_sorted(t_stack **stack_a);
void		sa(t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rra(t_stack **stack_a);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_three(t_stack **stack_a);
void		ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_stack(t_stack **stack_a);
void		ft_radix(t_stack **stack_a, t_stack **stack_b);

#endif