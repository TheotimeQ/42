/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:58:15 by tquere            #+#    #+#             */
/*   Updated: 2022/07/07 18:23:07 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}	

void	test_0(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
}

void	ft_putnbr(int nb)
{	
	long int	nb_test;
	int			digit_test;
	int			digit_to_print;

	digit_test = 1 ;
	nb_test = 1 ;
	if (nb < 0)
	{	
		nb_test = -1 ;
		ft_putchar('-');
	}
	while (digit_test != 0)
	{	
		digit_test = nb / nb_test ;
		nb_test = nb_test * 10 ;
	}
	nb_test = nb_test / 100 ;
	test_0(nb);
	while (nb_test != 0)
	{		
		digit_to_print = nb / nb_test ;
		ft_putchar(digit_to_print + 48);
		nb = nb - digit_to_print * nb_test;
		nb_test = nb_test / 10 ;
	}
}
