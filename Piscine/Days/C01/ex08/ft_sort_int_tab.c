/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:09:56 by tquere            #+#    #+#             */
/*   Updated: 2022/07/09 15:41:19 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	get_minimum(int *tab, int size, int start_index)
{
	int	min;
	int	index;

	min = tab[start_index];
	while (start_index < size)
	{
		if (tab[start_index] <= min)
		{
			min = tab[start_index];
			index = start_index ;
		}
		start_index++;
	}
	return (index);
}

void	ft_swap(int *a, int *b)
{
	int	c ;

	c = *b ;
	*b = *a ;
	*a = c ;
}

void	ft_sort_int_tab(int *tab, int size)
{	
	int	i ;
	int	min_index ;

	i = 0 ;
	while (i < size)
	{
		min_index = get_minimum(tab, size, i);
		ft_swap(&tab[i], &tab[min_index]);
		i++ ;
	}
}	
