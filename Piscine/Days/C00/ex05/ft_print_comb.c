/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:57:34 by tquere            #+#    #+#             */
/*   Updated: 2022/07/07 17:50:44 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	showchar(int a, int b, int c)
{
	a += '0';
	b += '0';
	c += '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	int	a ;
	int	b ;
	int	c ;

	a = 0 ;
	b = 1 ;
	c = 2 ;
	while (a <= 9)
	{
		while (b <= 9)
		{
			while (c <= 9)
			{
				showchar(a, b, c);
				c++;
			}
			b++;
			c = b + 1;
		}
		a++;
		b = a ;
	}
}
