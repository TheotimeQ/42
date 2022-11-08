/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:09 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 14:51:47 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		index;

	index = 0;
	while (((char *) s)[index] && index < n)
	{
		((char *) s)[index] = 0;
		index++;
	}
}
