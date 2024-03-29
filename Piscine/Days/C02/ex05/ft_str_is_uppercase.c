/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:37:52 by tquere            #+#    #+#             */
/*   Updated: 2022/07/10 11:38:21 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
	{
		if (65 <= str[i] && str[i] <= 90)
			i++;
		else
			return (0);
	}
	return (1);
}
