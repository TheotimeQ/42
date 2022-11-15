/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:49:44 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 15:37:09 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char	*add_zeros(char *str, t_flag *all_flag, int sign)
{	
	char	*cat;
	int		index;

	index = ft_strlen(str);
	if (all_flag->flag_point)
	{
		while (index < all_flag->point_right)
		{
			cat = ft_strdup("0");
			str = my_strcat(cat, str);
			index++;
		}
	}
	if (all_flag->flag_zeros && !all_flag->flag_point)
	{	
		index = ft_strlen(str) + sign;
		while (index < all_flag->point_left)
		{
			cat = ft_strdup("0");
			str = my_strcat(cat, str);
			index++;
		}
	}
	return (str);
}

char	*put_0(char *str, t_flag *all_flag)
{
	char	*cat;
	int		sign;

	sign = 0;
	if (str && str[0] == '-')
	{	
		cat = ft_substr(str, 1, ft_strlen(str));
		free(str);
		str = cat;
		sign = 1;
	}
	str = add_zeros(str, all_flag, sign);
	if (sign == 1)
	{
		cat = ft_strdup("-");
		str = my_strcat(cat, str);
	}
	return (str);
}
