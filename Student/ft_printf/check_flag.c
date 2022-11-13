/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:55:16 by tquere            #+#    #+#             */
/*   Updated: 2022/11/13 16:09:51 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*put_0(char *str, t_flag *all_flag)
{
	int		index;
	char	*cat;
	int		sign;

	index = 0;
	if (all_flag->flag_point == 1)
	{	
		if (str[0] == '-')
		{	
			cat = ft_substr(str, 1, ft_strlen(str));
			free(str);
			str = cat;
			sign = 1;
		}
		index = ft_strlen(str);
		while (index < all_flag->point_right)
		{
			cat = ft_strdup("0");
			str = my_strcat(cat, str);
			index++;
		}
		if (sign)
		{
			cat = ft_strdup("-");
			str = my_strcat(cat, str);
		}
	}
	return (str);
}

char	*my_strcat(char *dest, char *src)
{
	size_t	index_dest;
	size_t	index_src;
	char	*new_str;

	new_str = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof(char));
	index_src = 0;
	index_dest = 0;
	while (dest[index_dest])
	{
		new_str[index_dest] = dest[index_dest];
		index_dest++;
	}
	while (src[index_src])
	{
		new_str[index_dest + index_src] = src[index_src];
		index_src++;
	}
	new_str[index_dest + index_src] = '\0';
	free(dest);
	free(src);
	return (new_str);
}

char	*print_str_flag(t_flag *all_flag, char *s)
{
	int		nb_space;
	int		nb_space_to_place;
	char	*cat;

	nb_space = 0;
	nb_space_to_place = 0;
	if (all_flag->point_right < 0)
		all_flag->point_right = ft_strlen(s);
	if (all_flag->flag_point == 1)
	{	
		if ((size_t)all_flag->point_right < ft_strlen(s) - 1)
		{
			s = ft_substr(s, 0, all_flag->point_right);
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
	}
	return (s);
}

static void	get_point_value(const char *str, t_flag *all_flag)
{
	char	c;

	c = str[all_flag->index];
	while ('0' <= c && c <= '9')
	{
		all_flag->point_left = all_flag->point_left * 10;
		all_flag->point_left += (str[all_flag->index] - 48);
		all_flag->index++;
		c = str[all_flag->index];
	}
	if (str[all_flag->index] == '.')
	{
		all_flag->flag_point = 1;
		all_flag->index++;
	}
	c = str[all_flag->index];
	while ('0' <= c && c <= '9')
	{
		all_flag->point_right = all_flag->point_right * 10;
		all_flag->point_right += (str[all_flag->index] - 48);
		all_flag->index++;
		c = str[all_flag->index];
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

	all_flag->flag_hash = 0;
	all_flag->flag_space = 0;
	all_flag->flag_plus = 0;
	all_flag->flag_minus = 0;
	all_flag->flag_zeros = 0;
	all_flag->flag_point = 0;
	all_flag->point_left = 0;
	all_flag->point_right = -1;

	while (check_flag_set(str[all_flag->index], "# +-O."))
	{
		if (str[all_flag->index] == '#' && all_flag->index++)
			all_flag->flag_hash = 1;
		if (str[all_flag->index] == ' ' && all_flag->index++)
			all_flag->flag_space = 1;
		if (str[all_flag->index] == '+' && all_flag->index++)
			all_flag->flag_plus = 1;
		if (str[all_flag->index] == '-' && all_flag->index++)
			all_flag->flag_minus = 1;
		if (str[all_flag->index] == 'O' && all_flag->index++)
			all_flag->flag_zeros = 1;
		get_point_value(str, all_flag);
	}
	s = all_test(str, arg, all_flag);
	s = print_str_flag(all_flag, s);
	return (s);
}
