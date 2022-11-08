/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:18 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 13:12:43 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../Header/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		index;

	index = 0;
	while (s[index])
	{
		write(1, &s[index++], fd);
	}
}
