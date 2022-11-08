/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:26 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 13:26:25 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../Header/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		index;

	index = 0;
	while (s[index])
	{
		write(1, &s[index++], fd);
	}
	write(1, "\n", fd);
}
