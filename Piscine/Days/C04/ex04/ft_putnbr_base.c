/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:03:27 by tquere            #+#    #+#             */
/*   Updated: 2022/07/12 11:03:28 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert_print(long int nb_long, int len_base, char *base)
{
	if (nb_long > 0)
	{
		convert_print(nb_long / len_base, len_base, base);
		ft_putchar(base[(nb_long % len_base)]);
	}
}

int	test_base(char *base)
{	
	int	len_base;
	int	i;

	len_base = 0;
	while (base[len_base])
	{	
		if (base[len_base] == '+' || base[len_base] == '-')
			return (0);
		i = 0 ;
		while (i < len_base)
		{
			if (base[len_base] == base[i])
				return (0);
			i++;
		}
		len_base++;
	}
	return (len_base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb_long;
	int			len_base;

	len_base = test_base(base);
	if (len_base <= 1)
		return ;
	nb_long = nbr;
	if (nbr < 0)
	{
		nb_long *= -1 ;
		ft_putchar('-');
	}
	if (nb_long == 0)
	{
		write(1, &base[0], 1);
	}
	if (nb_long > 0)
	{
		convert_print(nb_long, len_base, base);
	}
}

int main()
{
    char base[30] = "0123456789";
    int    nbr = -2147483648;
    ft_putnbr_base(nbr, base);
}