/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:23:18 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/18 20:21:09 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char *str)
{
    int i;

    i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while(str[i])
	{	
		if (!('0' <= str[i] && str[i] <= '9'))
		    return (0);
		i++;
	}
	return (1);
}
