/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:06 by tquere            #+#    #+#             */
/*   Updated: 2022/12/22 09:59:45 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	check_nb(t_env *e, long int nb)
{
	if (nb < 0)
	{
		write(2, "Error : Wrong input\n", 20);
		free_exit(e, 1);
	}
	return (nb);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	index;

	if (s == NULL)
		return (0);
	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{	
		if (!('0' <= str[i] && str[i] <= '9'))
			return ("-1");
		i++;
	}
	return (str);
}

long int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	int long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb *= sign;
	return (nb);
}

void	ft_putnbr(long long int nb)
{	
	char	c;

	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = (nb + '0');
		write(1, &c, 1);
	}
}
