/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:22:22 by tquere            #+#    #+#             */
/*   Updated: 2022/07/25 21:51:56 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct	s_list
{
	int				i;
	char			c;
	struct s_list	*next;
};

void	aff_list(struct s_list *begin)
{
	while (begin)
	{
		printf("%d\n", begin->i);
		begin = begin->next;
	}
}

int	main(void)
{
	struct s_list	elem1;
	struct s_list	elem2;
	struct s_list	elem3;
	struct s_list	*begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = 0;

	elem1.i = 42;
	elem2.i = 84;
	elem3.i = 53;

	printf("%d \n", elem3.i);
	printf("%d \n", elem2.next->i);
	printf("%d \n", elem1.next->next->i);

	aff_list(begin);

	return (0);
}
