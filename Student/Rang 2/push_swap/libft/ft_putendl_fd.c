/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:26 by tquere            #+#    #+#             */
/*   Updated: 2022/11/27 16:48:29 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		write(fd, &s[index++], 1);
	}
	write(fd, "\n", 1);
}
