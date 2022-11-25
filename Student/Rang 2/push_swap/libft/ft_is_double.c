/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:49:05 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/25 08:17:22 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_is_double(int *tab, int size)
{
    int i;
    int j;

    i = 0;
	while (i < size)
	{	
        j = i + 1;
        while (j < size)
        {	
            if (tab[i] == tab[j])
                return (1);
            j++;
        }
        i++;
	}
    return (0);
}
