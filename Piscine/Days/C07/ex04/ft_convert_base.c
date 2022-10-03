/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:24:42 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 19:43:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	verif_base(char *base);

int	ft_char_is_from(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i])
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_itoa_base(char *dest, char *base, int nb, int index)
{
	int	size_base;

	size_base = ft_strlen(base);
	if (nb < 0)
	{
		dest[0] = '-';
		dest[1] = base [nb % size_base * -1];
		if (nb < -size_base + 1)
			ft_itoa_base(dest, base, nb / size_base * -1, index + 2);
		return (dest);
	}
	else
	{
		if (nb > size_base - 1)
			ft_itoa_base(dest, base, nb / size_base, index + 1);
		dest[index] = base[nb % size_base];
		return (dest);
	}
}

void	ft_rev_str(char *str)
{
	int		i;
	int		endindx;
	char	mem;

	if (str[0] == '-')
		str++;
	endindx = ft_strlen(str) - 1;
	i = 0;
	while (i < endindx)
	{
		mem = str[i];
		str[i] = str[endindx];
		str[endindx] = mem;
		i++;
		endindx--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		mem;
	int		size_base_to;
	int		size_dest;
	char	*dest;
	int		temp;

	size_base_to = 0;
	if (!verif_base(base_to) || !verif_base(base_from))
		return (NULL);
	mem = ft_atoi_base(nbr, base_from);
	temp = mem;
	size_base_to = ft_strlen(base_to);
	size_dest = 2;
	if (mem < 0)
		size_dest++;
	while (mem >= size_base_to || mem <= -size_base_to)
	{
		mem /= size_base_to;
		size_dest++;
	}
	dest = (char *)malloc(sizeof(char) * (size_dest));
	dest = ft_itoa_base(dest, base_to, temp, 0);
	dest[size_dest - 1] = '\0';
	ft_rev_str(dest);
	return (dest);
}
