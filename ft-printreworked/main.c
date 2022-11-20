/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:18 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 15:44:00 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{	
	printf("   RETURN:%d \n",ft_printf(" %p %p ", NULL, NULL));
	printf("   RETURN:%d \n",printf(" %p %p ", NULL, NULL)); 
	return (0);
}
