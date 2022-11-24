/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:56:52 by tquere            #+#    #+#             */
/*   Updated: 2022/11/24 17:56:53 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_list(t_stack *a, t_stack *b)
{
	int	i;

	printf("\n|a    b\n|\n");
	i = a->index - 1;
	if (a->index < b->index)
		i = b->index - 1;
	while (i >= 0)
	{
		if (i < a->index)
			printf("|%d    ", a->data[i]);
		else
			printf("|     ");
		if (i < b->index)
			printf("%d    ", b->data[i]);
		printf("\n");
		i--;
	}
	printf("\n");
}
