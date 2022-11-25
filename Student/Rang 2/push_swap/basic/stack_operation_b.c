/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:46:44 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/19 09:54:40 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sb(t_stack *a)
{
	swap_stack(a);
	ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->index > 0)
	{
		push_stack(b, a->data[a->index - 1]);
		pop_stack(a);
		ft_putstr_fd("pb\n", 1);
	}
}

void	rb(t_stack *b)
{
	rotate_stack(1, b);
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stack *b)
{
	rotate_stack(-1, b);
	ft_putstr_fd("rrb\n", 1);
}
