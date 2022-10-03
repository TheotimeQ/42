/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:54:31 by tquere            #+#    #+#             */
/*   Updated: 2022/07/13 10:54:33 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	rec_loop(int n)
{	
	if (n < 2)
		return (n);
	else
		return (rec_loop(n - 1) + rec_loop(n - 2));
}

int	ft_fibonacci(int index)
{	
	if (index >= 0)
		return (rec_loop(index));
	return (-1);
}
