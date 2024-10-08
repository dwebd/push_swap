/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimirzoe <dimirzoe@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:33:47 by fishaq            #+#    #+#             */
/*   Updated: 2024/09/22 14:28:14 by dimirzoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	**my_split(const char *s, char c);

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int						error_syntax(char *str);
int						error_reptition(t_stack_node *a, int nbr);
void					free_stack(t_stack_node **stack);
void					free_matrix(char **av);
int						ft_isspace(char c);
int						is_space(const char *str);
void					stack_init(t_stack_node **a, char **av, char **am);
void					error_free(t_stack_node **a, char **am);
void					*ft_calloc(int count, int size);
void					*ft_bzero(void *str, int n);
t_stack_node			*find_last_node(t_stack_node *n);
bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *a);
void					sort_three(t_stack_node **a);
t_stack_node			*find_max(t_stack_node *a);
void					current_index(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *a);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					prep_to_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					init_nodesa(t_stack_node *a, t_stack_node *b);
void					init_nodesb(t_stack_node *a, t_stack_node *b);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheap_node);
void					set_cheapest(t_stack_node *s);
char					*ft_strcat(char *dest, const char *s2);
void					rrb(t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);

#endif
