/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:54:09 by tquere            #+#    #+#             */
/*   Updated: 2022/07/13 10:54:09 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	rec_loop(int nb, int power, int i)
{	
	i++;
	if (i <= power)
		return (nb * rec_loop(nb, power, i));
	return (1);
}

int	ft_recursive_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	nb = nb * rec_loop(nb, power, i);
	return (nb);
}
