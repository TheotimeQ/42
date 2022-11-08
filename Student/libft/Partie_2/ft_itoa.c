/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:36 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 11:46:15 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../Header/libft.h"

static int	len_int(int n)
{
	int	index;

	index = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

char	*ft_itoa(int n)
{
	char	*char_nb;
	int		index;
	int		len_nb;

	index = 0;
	len_nb = len_int(n);
	char_nb = malloc(sizeof(char) * (len_nb + 2));
	if (char_nb == NULL)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		len_nb += 1;
		char_nb[0] = '-';
	}
	if (n == 0)
		char_nb[0] = '0';
	while (n > 0)
	{
		char_nb[len_nb - index - 1] = "0123456789"[n % 10];
		n /= 10;
		index++;
	}
	char_nb[len_nb] = '\0';
	return (char_nb);
}
