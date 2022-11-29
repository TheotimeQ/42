/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:51:50 by tquere            #+#    #+#             */
/*   Updated: 2022/11/29 12:20:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(int direction, t_stack *s)
{
	int		tmp;
	size_t	index;

	if (direction == 1)
	{
		index = s->index - 1;
		while (index > 0)
		{
			tmp = s->data[index];
			s->data[index] = s->data[index - 1];
			s->data[index - 1] = tmp;
			index--;
		}
	}
	if (direction == -1)
	{
		index = 0;
		while (index < s->index - 1)
		{
			tmp = s->data[index];
			s->data[index] = s->data[index + 1];
			s->data[index + 1] = tmp;
			index++;
		}
	}
}

void	push_stack(t_stack *s, int value)
{
	s->data[s->index] = value;
	s->index++;
}

int	pop_stack(t_stack *s)
{
	int	poped;

	if (s->index > 0)
	{
		poped = s->data[s->index - 1];
		s->index--;
		return (poped);
	}
	return (0);
}

void	swap_stack(t_stack *s)
{
	int	tmp;

	tmp = s->data[s->index - 1];
	s->data[s->index - 1] = s->data[s->index - 2];
	s->data[s->index - 2] = tmp;
}
