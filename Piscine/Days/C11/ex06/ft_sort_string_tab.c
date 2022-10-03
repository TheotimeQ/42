/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:49:15 by tquere            #+#    #+#             */
/*   Updated: 2022/07/20 06:49:16 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[j], tab[j - 1]) < 0)
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
