/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:45:54 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/25 10:26:51 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(1, a);
	rotate_stack(1, b);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_stack(-1, a);
	rotate_stack(-1, b);
	ft_putstr_fd("rrr\n", 1);
}
