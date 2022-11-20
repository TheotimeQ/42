/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:55:16 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 15:01:36 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*print_str_flag(t_flag *all_flag, char *s)
{
	int		nb_space;
	int		nb_space_to_place;
	char	*cat;

	nb_space = 0;
	nb_space_to_place = 0;
	if (all_flag->point_right < (int)ft_strlen(s))
		all_flag->point_right = ft_strlen(s);
	if (all_flag->flag_point == 1 && all_flag->point_right == 0)
	{	
		s = ft_substr(s, 0, 0);
	}
	nb_space_to_place = all_flag->point_left - ft_strlen(s);
	while (nb_space++ < nb_space_to_place)
	{	
		cat = ft_strdup(" ");
		if (all_flag->flag_minus)
			s = my_strcat(s, cat);
		else
			s = my_strcat(cat, s);
	}
	return (s);
}

static void	get_first_nb(const char *str, t_flag *all_flag)
{
	while ('0' <= str[all_flag->index] && str[all_flag->index] <= '9')
	{	
		if (all_flag->point_left < 0)
			all_flag->point_left = 0;
		all_flag->point_left = all_flag->point_left * 10;
		all_flag->point_left += (str[all_flag->index] - 48);
		all_flag->index++;
	}
}

static void	get_point_value(const char *str, va_list arg, t_flag *all_flag)
{
	if (str[all_flag->index] == '.')
	{
		all_flag->flag_point = 1;
		all_flag->index++;
	}
	if (str[all_flag->index] == '*' && all_flag->index++)
			all_flag->point_right = va_arg(arg, int);
	else
	{
		while ('0' <= str[all_flag->index] && str[all_flag->index] <= '9')
		{
			if (all_flag->point_right < 0)
				all_flag->point_right = 0;
			all_flag->point_right = all_flag->point_right * 10;
			all_flag->point_right += (str[all_flag->index] - 48);
			all_flag->index++;
		}
	}
}

static int	check_flag_set(char c, const char *set)
{	
	int	index;

	index = 0;
	while (set[index])
	{
		if (set[index++] == c || ('0' <= c && c <= '9'))
			return (1);
	}
	return (0);
}

char	*ck_flag(const char *str, va_list arg, t_flag *all_flag)
{	
	char	*s;

	while (check_flag_set(str[all_flag->index], "#*+-O."))
	{	
		
		if (str[all_flag->index] == '0' && all_flag->index++)
			all_flag->flag_zeros = 1;
		if (str[all_flag->index] == '*' && all_flag->index++)
		{
			all_flag->point_left = va_arg(arg, int);
			if (all_flag->point_left < 0)
			{
				all_flag->flag_minus = 1;
				all_flag->point_left *= -1;
			}
		}
		if ('0' <= str[all_flag->index] && str[all_flag->index] <= '9'
			&& all_flag->point_right < 0)
			get_first_nb(str, all_flag);
		if (str[all_flag->index] == '.')
			get_point_value(str, arg, all_flag);
			
		// if (str[all_flag->index] == ' ' && all_flag->index++)
		// 	all_flag->flag_space = 1;

		if (str[all_flag->index] == '#' && all_flag->index++)
			all_flag->flag_hash = 1;
		if (str[all_flag->index] == '*' && all_flag->index++)
			all_flag->point_left = va_arg(arg, int);
		if (str[all_flag->index] == '+' && all_flag->index++)
			all_flag->flag_plus = 1;
		if (str[all_flag->index] == '-' && all_flag->index++)
			all_flag->flag_minus = 1;
	}
	// printf(" TEST %d %d TEST",all_flag->point_left,all_flag->point_right);
	s = all_test(str, arg, all_flag);
	s = print_str_flag(all_flag, s);
	return (s);
}
