/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:49:27 by tquere            #+#    #+#             */
/*   Updated: 2022/07/20 06:49:29 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i ;
	int		j;
	char	*new_str;

	i = 1;
	while (tab[i])
	{	
		j = i + 1;
		while (tab[j])
		{
			if ((*cmp)(tab[j], tab[j - 1]) < 0)
			{
				new_str = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = new_str;
			}
			j++;
		}
		i++;
	}
}
