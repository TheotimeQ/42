/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:39:47 by tquere            #+#    #+#             */
/*   Updated: 2022/07/10 11:39:49 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
	{
		if (31 < str[i])
			i++;
		else
			return (0);
	}
	return (1);
}
