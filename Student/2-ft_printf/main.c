/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:18 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 17:09:19 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	printf("---Testing Printf------\n\n");

	char 			c = 'D';					//c
	char 			s[] = "Ceci est un test";	//s
	void 			*p = &s;					//p
	float			d = -5.500;						//d
	int				i = -120;					//i
	float			unsigned_base_dix = -5.5;		//u

	printf("PRINTF - Char : %c\n",c);
	ft_printf("Char : %c\n",c);
	printf("\n");

	printf("PRINTF - String : %s\n",s);
	ft_printf("String : %s\n",s);
	printf("\n");

	printf("PRINTF - pointer : %p\n",p);
	ft_printf("pointer : %p\n",p);
	printf("\n");

	printf("PRINTF - decimal : %f\n",d);
	ft_printf("decimal : %d\n",d);
	printf("\n");

	printf("PRINTF - entier : %i\n",i);
	ft_printf("entier : %i\n",i);
	printf("\n");

	printf("PRINTF - Unsigned base 10 : %f\n",unsigned_base_dix);
	ft_printf("Unsigned base 10 : %u\n",unsigned_base_dix);
	printf("\n");

	printf("PRINTF - hex : %x\n",i);
	ft_printf("hex : %x\n",i);
	printf("\n");

	printf("PRINTF - HEX : %X\n",i);
	ft_printf("HEX : %X\n",i);
	printf("\n");

	printf("PRINTF - Pourcent : %%\n");
	ft_printf("Pourcent : %%\n");
	printf("\n");

	printf("  PRINTF: \n%c \n%s \n%p \n%f \n%i \n%f \n%x \n%X \n%%\n",c,s,p,d,i,unsigned_base_dix,i,i);
	ft_printf("\nMYPRINTF: \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%\n",c,s,p,d,i,unsigned_base_dix,i,i);
	printf("\n");
	return (0);
}
