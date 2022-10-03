/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:03:38 by tquere            #+#    #+#             */
/*   Updated: 2022/07/12 11:03:40 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	calc_power(char *str, int index, char *base, int len_base)
{
	int			in_base;
	long int	power;
	int			i;
	int			len_nb;

	in_base = 1;
	len_nb = 0;
	power = 1;
	while (in_base && str[index + len_nb])
	{
		i = 0;
		in_base = 0;
		while (base[i])
		{	
			if (str[index + len_nb] == base[i])
			{	
				in_base = 1;
				power *= len_base;
				len_nb++;
				break ;
			}
			i++;
		}
	}
	return (power /= len_base);
}

int	count_number(char *str, int index, char *base, int len_base)
{	
	long int	power;
	int			i;
	int			nb;

	nb = 0;
	i = 0;
	power = calc_power(str, index, base, len_base);
	while (power != 0)
	{	
		i = 0;
		while (base[i])
		{	
			if (str[index] == base[i])
				break ;
			i++;
		}
		nb += i * power ;
		power /= len_base;
		index++;
	}
	return (nb);
}

int	count_minus_space(char *str, char *base, int len_base)
{	
	int	sign;
	int	nb;
	int	index;

	sign = 1;
	index = 0;
	while ((str[index] == '\t' || str[index] == '\n' || str[index] == '\v'
			|| str[index] == '\f' || str[index] == '\r'
			|| str[index] == ' ') && str[index])
	{
		index++;
	}
	while ((str[index] == '+' || str[index] == '-') && str[index])
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	nb = count_number(str, index, base, len_base);
	return (nb * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int			index;
	int			len_base;
	int			i;

	len_base = 0;
	index = 0 ;
	while (base[len_base])
	{	
		if (base[len_base] == '+' || base[len_base] == '-'
			|| base[len_base] == '\t' || base[len_base] == '\n'
			|| base[len_base] == '\v' || base[len_base] == '\f'
			|| base[len_base] == '\r' || base[len_base] == ' ')
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
	if (len_base <= 1)
		return (0);
	return (count_minus_space(str, base, len_base));
}
