/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:21 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 16:34:25 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/libft.h"

int	ft_tolower(int c)
{
	if ('a' <= c && c <= 'Z')
		c = c + 32 ;
	return (c);
}
