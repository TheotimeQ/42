/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:45:54 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/29 16:30:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, t_data *data)
{
	swap_stack(a);
	swap_stack(b);
	if (data->print)
		ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack *a, t_stack *b, t_data *data)
{
	rotate_stack(1, a);
	rotate_stack(1, b);
	if (data->print)
		ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *a, t_stack *b, t_data *data)
{
	rotate_stack(-1, a);
	rotate_stack(-1, b);
	if (data->print)
		ft_putstr_fd("rrr\n", 1);
}
