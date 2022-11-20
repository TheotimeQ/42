/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:44:41 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 17:15:12 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	len_int(unsigned int n)
{
	int	index;

	index = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

static int	get_char(unsigned int nbr, int len_nb, char *char_nb)
{	
	int			index;

	index = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len_nb += 1;
		char_nb[0] = '-';
	}
	if (nbr == 0)
		char_nb[0] = '0';
	while (nbr > 0)
	{
		char_nb[len_nb - index++ - 1] = "0123456789"[nbr % 10];
		nbr /= 10;
	}
	return (len_nb);
}

static char	*my_ft_itoa(unsigned int n)
{
	char					*char_nb;
	int						len_nb;
	unsigned long int		nbr;

	nbr = n;
	len_nb = len_int(nbr);
	char_nb = malloc(sizeof(char) * (len_nb + 2));
	if (char_nb == NULL)
		return (NULL);
	len_nb = get_char(nbr, len_nb, char_nb);
	char_nb[len_nb] = '\0';
	return (char_nb);
}

char	*print_u(va_list arg, t_flag *all_flag)
{
	unsigned int				u;
	char						*str;
	char						*cat_left;

	u = va_arg(arg, unsigned int);
	if (all_flag->flag_point && all_flag->point_right <= 0 && u == 0)
		str = ft_strdup("");
	else
		str = my_ft_itoa(u);
	if (str == NULL)
	{
		// all_flag->error = 1;
		return (NULL);
	}
	if (all_flag->flag_plus && u >= 0 && str)
	{	
		if (str[0] != '-')
		{
			cat_left = ft_strdup("+");
			str = my_strcat(cat_left, str);
		}
	}
	str = put_0(str, all_flag);
	if (str == NULL)
		return (ft_strdup(""));
	return (str);
}
