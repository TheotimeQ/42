/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:23:52 by tquere            #+#    #+#             */
/*   Updated: 2022/07/19 14:23:54 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c, int output);
void	ft_putstr(char *str, int output);

void	print_str(char *str, int size)
{
	int	index;

	index = 0;
	if (size < 1)
		return ;
	ft_putstr("|", 1);
	while (index < size)
	{	
		if (' ' <= str[index] && str[index] <= '~' )
			ft_putchar(str[index], 1);
		else
			ft_putchar('.', 1);
		index++;
	}
	ft_putstr("|", 1);
}
