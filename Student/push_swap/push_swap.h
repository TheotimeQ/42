/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:31:47 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/19 09:57:44 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	int		min;
	int		min_index;
	int		dir_rot;
	int		nb_rot;

}	t_data;

typedef struct s_pile
{
	int	*data;
	int	index;
}	t_stack;

void	rotate_stack(int direction, t_stack *s);
void	push_stack(t_stack *s, int value);
int		pop_stack(t_stack *s);
void	swap_stack(t_stack *s);
void	clear_stack(t_stack *s);
void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	sb(t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	resolve_push_swap(t_stack *a, t_stack *b);
void	print_list(t_stack *a, t_stack *b);

#endif