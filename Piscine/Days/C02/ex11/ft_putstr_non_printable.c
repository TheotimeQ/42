/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:41:20 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 06:59:04 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned int	i;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 31) || (str[i] >= 127))
		{
			write(1, "\\", 1);
			write(1, &hex[((unsigned char) str[i]) / 16], 1);
			write(1, &hex[((unsigned char) str[i]) % 16], 1);
		}
		else
		{
			write (1, &str[i], 1);
		}
		i++;
	}
}
