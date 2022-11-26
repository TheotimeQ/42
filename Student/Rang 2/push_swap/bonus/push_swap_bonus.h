
#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

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

char	    *get_next_line(int fd);
char	    *save(char *str, char *buffer, int i);
void	    *ft_memset(void *b, int c, size_t len);

void        listen_stdin();

void		get_min(t_stack *a, t_data *data);
void		push_all_b(t_stack *a, t_stack *b);
void		get_rot_dir(t_stack *a, t_data *data);
void		rot_min_to_top(t_stack *a, t_data *data);
int			is_sorted(int comp, t_stack *stack);

void		rotate_stack(int direction, t_stack *s);
void		push_stack(t_stack *s, int value);
int			pop_stack(t_stack *s);
void		swap_stack(t_stack *s);
void		clear_stack(t_stack *s);

void		sa(t_stack *a);
void		pa(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rra(t_stack *a);
void		sb(t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		rb(t_stack *b);
void		rrb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		resolve_push_swap(t_stack *a, t_stack *b);
void		print_list(t_stack *a, t_stack *b);

#endif