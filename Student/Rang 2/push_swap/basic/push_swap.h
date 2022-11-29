/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:31:47 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/29 18:27:13 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef struct s_data
{	
	size_t		print;

	int			*chunk;
	size_t		nb_chunk;
	size_t		current_chunk;

	int			bot_key;
	size_t		bot_key_index;

	int			top_key;
	size_t		top_key_index;

	size_t		index_to_place_key;

	int			key;
	size_t		key_index;
	int			dir_rot;
	int			nb_rot;

	int			*test_result;
	size_t		nb_test;

	int			max;
	int			min;
	id_t		min_index;

	size_t		nb_moove;

}	t_data;

typedef struct s_pile
{
	int		*data;
	size_t	index;
}	t_stack;

size_t		init_stack(t_stack *a, t_stack *b, int argc, char **argv);

void		resolve_push_swap(t_stack *a, t_stack *b, t_data *data);

void		get_min(t_stack *a, t_data *data);
void		push_all_b(t_stack *a, t_stack *b, t_data *data);
void		get_rot_dir(t_stack *b, t_data *data);
void		rot_a(t_stack *a, t_data *data);
void		rot_b(t_stack *a, t_data *data);
size_t		is_sorted(int comp, t_stack *stack);

void		rotate_stack(int direction, t_stack *s);
void		push_stack(t_stack *s, int value);
int			pop_stack(t_stack *s);
void		swap_stack(t_stack *s);
void		clear_stack(t_stack *s);
void		free_stack(t_stack *a, t_stack *b);

void		sa(t_stack *a, t_data *data);
void		pa(t_stack *a, t_stack *b, t_data *data);
void		ra(t_stack *a, t_data *data);
void		rra(t_stack *a, t_data *data);
void		sb(t_stack *b, t_data *data);
void		pb(t_stack *a, t_stack *b, t_data *data);
void		rb(t_stack *b, t_data *data);
void		rrb(t_stack *b, t_data *data);
void		ss(t_stack *a, t_stack *b, t_data *data);
void		rr(t_stack *a, t_stack *b, t_data *data);
void		rrr(t_stack *a, t_stack *b, t_data *data);

void		print_list(t_stack *a, t_stack *b);

#endif