/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:28:17 by tquere            #+#    #+#             */
/*   Updated: 2022/12/03 09:28:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *a, t_data *data)
{
	swap_stack(a);
	if (data->print)
		ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack *a, t_stack *b, t_data *data)
{
	if (a->index > 0)
	{
		push_stack(b, a->data[a->index - 1]);
		pop_stack(a);
		if (data->print)
			ft_putstr_fd("pb\n", 1);
	}
}

void	rb(t_stack *b, t_data *data)
{
	rotate_stack(1, b);
	if (data->print)
		ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack *b, t_data *data)
{
	rotate_stack(-1, b);
	if (data->print)
		ft_putstr_fd("rrb\n", 1);
}
