/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:53:39 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 11:56:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rec_loop(int nb, int i)
{	
	i++;
	if (i <= nb)
		return (i * rec_loop(nb, i));
	return (1);
}

int	ft_recursive_factorial(int nb)
{
	int	i;
	int	fact;

	i = 1;
	fact = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	fact = i * rec_loop(nb, i);
	return (fact);
}
