/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:12 by tquere            #+#    #+#             */
/*   Updated: 2022/11/13 13:53:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*mem;

	if (count > SIZE_MAX / size && size > 0)
		return (NULL);
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
