/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:03:04 by tquere            #+#    #+#             */
/*   Updated: 2022/07/12 11:03:06 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}	

void	rec(long int nb_long)
{
	if (nb_long > 0)
	{
		rec(nb_long / 10);
		ft_putchar(nb_long % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{	
	long int	nb_long ;

	nb_long = nb ;
	if (nb_long < 0)
	{
		write(1, "-", 1);
		nb_long *= -1;
	}
	if (nb_long == 0)
	{
		write(1, "0", 1);
	}
	if (nb_long > 0)
	{
		rec(nb_long);
	}
}
