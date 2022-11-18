/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:47:52 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/18 13:27:53 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_putstr_fd("sa\n",1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->index > 0)
	{
		push_stack(a, b->data[b->index - 1]);
		pop_stack(b);
		ft_putstr_fd("pa\n",1);
	}
}

void	ra(t_stack *a)
{	
	rotate_stack(1, a);
	ft_putstr_fd("ra\n",1);
}

void	rra(t_stack *a)
{	
	rotate_stack(-1, a);
	ft_putstr_fd("rra\n",1);
}