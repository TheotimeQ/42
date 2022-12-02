/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:59:13 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/02 08:19:18 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_a(t_stack *a, t_data *data)
{
	t_stack	*cpy_a;
	int		index;

	cpy_a = malloc(sizeof(t_stack));
	if(!cpy_a)
		leave(data);
	cpy_a->index = a->index;
	cpy_a->data = malloc(sizeof(int) * cpy_a->index);
	if(!cpy_a->data)
	{
		free(cpy_a);
		leave(data);
	}
	index = 0;
	while (index < a->index)
	{
		cpy_a->data[index] =  a->data[index];
		index++;
	}
	return (cpy_a);
}

void	data_cpy(t_stack *a,t_stack *cpy)
{
	int		index;
	
	index = 0;
	while (index < a->index)
	{
		cpy->data[index] =  a->data[index];
		index++;
	}
}