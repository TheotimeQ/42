/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:34:18 by tquere            #+#    #+#             */
/*   Updated: 2022/07/10 09:44:22 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(char *tab, int n)
{
	int	i ;

	i = 0 ;
	while (i < n)
	{
		ft_putchar(tab[i]);
		i++;
	}
	if (tab[0] != '9' - n + 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	rec(int index, char *tab, int n)
{
	tab[index - 1] = tab[index - 2] + 1 ;
	while (tab[index - 1] <= '9' - n + index)
	{
		if (index == n)
		{
			print_tab(tab, n);
			tab[index - 1]++;
		}
		else
			rec(index + 1, tab, n);
	}
	tab[index - 2]++;
}

void	ft_print_combn(int n)
{
	char	tab[9];
	int		index;
	int		i;

	i = 0;
	if (n <= 0 || n > 9)
		return ;
	while (i < n)
	{
		tab[i] = '0' + i;
		i++;
	}
	index = 1 ;
	tab[index - 1] = '0' ;
	while (tab[index - 1] <= '9' - n + index)
	{
		if (index == n)
		{
			print_tab(tab, n);
			tab[index - 1]++;
		}
		else
			rec(index + 1, tab, n);
	}
}	
