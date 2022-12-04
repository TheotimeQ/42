/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 16:57:09 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# define NB_TEST 50

typedef struct s_pile
{
	int		*data;
	int		index;
}	t_stack;

typedef struct s_data
{	
	t_stack		*a;
	t_stack		*b;
	t_stack		*sorted_a;
	int			print;
	int			*chunk;
	int			*saved_chunk;
	int			nb_chunk;
	int			current_chunk;
	int			bot_key;
	int			bot_key_index;
	int			top_key;
	int			top_key_index;
	int			index_to_place_key;
	int			key;
	int			key_index;
	int			dir_rot_a;
	int			nb_rot_a;
	int			dir_rot_b;
	int			nb_rot_b;
	int			min_moove;
	int			nb_chunk_choosed;
	int			nb_test;
	int			max;
	int			max_index;
	int			min;
	int			min_index;
	int			nb_moove;

}	t_data;

void		print_list(t_stack *a, t_stack *b);
void		test_min_to_top(t_stack *a, t_data *data);
void		chosse_key(t_stack *a, t_data *data);
int			cut_chunk_egale(t_data *data);
int			cut_chunk(t_data *data, t_stack *a);
int			scan_from_top(t_stack *a, t_data *data);
int			scan_from_bot(t_stack *a, t_data *data);
void		get_min(t_stack *a, t_data *data);
void		get_max(t_stack *a, t_data *data);
void		get_rot_dir_a(t_stack *b, t_data *data);
void		get_rot_dir_b(t_stack *b, t_data *data);
void		get_rot_min(t_stack *a, t_data *data);
void		get_rot_max(t_stack *b, t_data *data);
void		rot_stack_opti(t_stack *a, t_stack *b, t_data *data);
void		resolve_one_test(t_stack *a, t_stack *b, t_data *data);
void		insert_key(t_stack *a, t_stack *b, t_data *data);
int			try_sort_a(t_stack *a, t_stack *b, t_data *data);
void		resolve_push_swap(t_stack *a, t_stack *b, t_data *data);
void		leave(t_data *data);
int			init_stack(t_data *data, int argc, char **argv);
void		push_all_b(t_stack *a, t_stack *b, t_data *data);
void		rot_a(t_stack *a, t_data *data);
void		rot_b(t_stack *a, t_data *data);
void		rot_and_swap(t_stack *a, t_data *data);
int			is_sorted(int comp, t_stack *stack);
t_stack		*copy_a(t_stack *a, t_data *data);
void		data_cpy(t_stack *a, t_stack *cpy);
void		rotate_stack(int direction, t_stack *s);
void		push_stack(t_stack *s, int value);
int			pop_stack(t_stack *s);
void		swap_stack(t_stack *s);
void		clear_stack(t_stack *s);
void		free_stack(t_stack *a);
void		free_data(t_data *data);
void		free_one_stack(t_stack *a);
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

#endif