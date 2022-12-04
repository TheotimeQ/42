/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_min_to_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:28:03 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 11:39:26 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_min_to_top(t_stack *a, t_data *data)
{
	t_stack	*cpy_a;

	data->nb_moove = 0;
	data->print = 0;
	cpy_a = copy_a(a, data);
	get_min(cpy_a, data);
	get_rot_min(cpy_a, data);
	rot_a(cpy_a, data);
	if (is_sorted(-1, cpy_a))
	{
		free_stack(cpy_a);
		data->nb_moove = 0;
		data->print = 1;
		get_min(a, data);
		get_rot_min(a, data);
		rot_a(a, data);
		data->min_moove = data->nb_moove;
		leave(data);
	}
	free_stack(cpy_a);
}
