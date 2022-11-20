/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 15:46:22 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// static void	flag_format(long int d, char *str, t_flag *all_flag)
// {
// 	char		*cat_left;

// 	if (all_flag->flag_plus && d >= 0 && str)
// 	{	
// 		if (str[0] != '-')
// 		{
// 			cat_left = ft_strdup("+");
// 			str = my_strcat(cat_left, str);
// 		}
// 	}
// 	if (all_flag->flag_space && str[0] != '-' && str[0] != '+')
// 	{
// 		cat_left = ft_strdup(" ");
// 		str = my_strcat(cat_left, str);
// 	}
// }

char	*print_d(va_list arg, t_flag *all_flag)
{
	long int	d;
	char		*str;
	char		*cat_left;

	d = va_arg(arg, long int);
	if (all_flag->flag_point && all_flag->point_right <= 0 && d == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(d);
	// flag_format(d, str, all_flag);
	if (all_flag->flag_plus && d >= 0 && str)
	{	
		if (str[0] != '-')
		{
			cat_left = ft_strdup("+");
			str = my_strcat(cat_left, str);
		}
	}
	if (all_flag->flag_space && str[0] != '-' && str[0] != '+')
	{
		cat_left = ft_strdup(" ");
		str = my_strcat(cat_left, str);
	}
	str = put_0(str, all_flag);
	if (str == NULL)
		return (ft_strdup(""));
	return (str);
}
