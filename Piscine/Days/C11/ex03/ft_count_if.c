/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:42:36 by tquere            #+#    #+#             */
/*   Updated: 2022/07/20 06:42:38 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		index;
	int		count;

	count = 0;
	index = 0;
	while (index < length)
	{
		if ((*f)(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}
