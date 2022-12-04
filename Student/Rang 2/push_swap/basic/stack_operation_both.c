/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:28:13 by tquere            #+#    #+#             */
/*   Updated: 2022/12/03 09:28:14 by tquere           ###   ########.fr       */
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
