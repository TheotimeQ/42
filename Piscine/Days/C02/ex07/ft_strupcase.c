/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:40:00 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 16:30:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
	{
		if (97 <= str[i] && str[i] <= 122)
			str[i] = str[i] - 32 ;
		i++;
	}
	return (str);
}
