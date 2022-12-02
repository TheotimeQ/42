/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_min_to_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:15:40 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/02 08:38:39 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_min_to_top(t_stack *a, t_data *data)
{
	t_stack		*cpy_a;
    
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


