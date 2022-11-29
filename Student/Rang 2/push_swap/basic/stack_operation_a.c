/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:47:52 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/29 16:30:44 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_data *data)
{
	swap_stack(a);
	if (data->print)
		ft_putstr_fd("sa\n", 1);
}

void	pa(t_stack *a, t_stack *b, t_data *data)
{
	if (b->index > 0)
	{
		push_stack(a, b->data[b->index - 1]);
		pop_stack(b);
		if (data->print)
			ft_putstr_fd("pa\n", 1);
	}
}

void	ra(t_stack *a, t_data *data)
{	
	rotate_stack(1, a);
	if (data->print)
		ft_putstr_fd("ra\n", 1);
}

void	rra(t_stack *a, t_data *data)
{	
	rotate_stack(-1, a);
	if (data->print)
		ft_putstr_fd("rra\n", 1);
}
