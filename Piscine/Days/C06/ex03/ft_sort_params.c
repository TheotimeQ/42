/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:39:23 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 04:17:08 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0 ;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	return (0);
}

void	sort(char **arg_tab)
{
	int		i ;
	int		j;
	char	*new_str;

	i = 1;
	while (arg_tab[i])
	{	
		j = 2;
		while (arg_tab[j])
		{
			if (ft_strcmp(arg_tab[j], arg_tab[j - 1]) < 0)
			{
				new_str = arg_tab[j];
				arg_tab[j] = arg_tab[j - 1];
				arg_tab[j - 1] = new_str;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	(void) argc;
	sort(argv);
	i = 1 ;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
		j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
