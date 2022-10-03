/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:48:57 by tquere            #+#    #+#             */
/*   Updated: 2022/07/20 06:48:59 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int		index;
	int		sign;

	if (length < 1)
		return (1);

	index = 1;
	sign = 0;
	while (sign == 0)
	{
		sign = (*f)(tab[index - 1], tab[index]);
		index++;
	}
	while (index < length )
	{	
		if ((*f)(tab[index - 1], tab[index]) != sign )
			return (0);
		index++;
	}
	return (1);
}
