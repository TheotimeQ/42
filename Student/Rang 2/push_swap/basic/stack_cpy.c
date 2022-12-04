/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:28:27 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 13:35:59 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_a(t_stack *a, t_data *data)
{
	t_stack	*cpy_a;
	int		index;

	cpy_a = malloc(sizeof(t_stack));
	if (!cpy_a)
		leave(data);
	cpy_a->index = a->index;
	cpy_a->data = malloc(sizeof(int) * cpy_a->index);
	if (!cpy_a->data)
	{
		free(cpy_a);
		leave(data);
	}
	index = 0;
	while (index < a->index)
	{
		cpy_a->data[index] = a->data[index];
		index++;
	}
	return (cpy_a);
}

void	data_cpy(t_stack *a, t_stack *cpy)
{
	int		index;

	index = 0;
	while (index < a->index)
	{
		cpy->data[index] = a->data[index];
		index++;
	}
	cpy->index = a->index;
}
