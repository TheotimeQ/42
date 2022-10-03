/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:53:55 by tquere            #+#    #+#             */
/*   Updated: 2022/07/13 10:53:56 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	power_nb;

	i = 1;
	power_nb = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		nb *= power_nb;
		i++;
	}
	return (nb);
}
