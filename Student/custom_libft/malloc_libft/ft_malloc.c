/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:19:09 by tquere            #+#    #+#             */
/*   Updated: 2022/11/21 16:57:28 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_malloc(size_t count, size_t size, t_gbc *gbc, size_t add_gbc)
{
	void	*mem;
	// void	**ptr_mem;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	if (!gbc)
		return (NULL);
	mem = malloc(count * size);
	// ptr_mem = &mem;
	// printf("malloc str= %p\n", mem);
	// printf("malloc &str %p\n\n", ptr_mem);
	if (mem == NULL)
	{
		gbc->malloc_error = 1;
		return (NULL);
	}
	if (add_gbc)
		gbc_add(mem, gbc);
	return (mem);
}
