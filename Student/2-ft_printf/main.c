/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:18 by tquere            #+#    #+#             */
/*   Updated: 2022/11/11 16:10:23 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

// malloc, free, write, va_start, va_arg, va_copy, va_end

// va_start définit arg_ptr comme étant le premier argument facultatif de la liste d’arguments à être passé à la fonction. L’argument arg_ptr doit être de type va_list. L’argument prev_param est le nom du paramètre obligatoire qui précède immédiatement le premier argument facultatif dans la liste d’arguments. Si prev_param est déclarée avec la classe de stockage register, le comportement de la macro est indéfini. va_start doit être utilisée avant la première utilisation de va_arg.
// va_arg récupère une valeur de type à partir de l’emplacement indiqué par arg_ptr et incrémente arg_ptr pour pointer vers le prochain argument de la liste en utilisant la taille de type pour déterminer le point de départ du prochain argument. va_arg peut être utilisé autant de fois que nécessaire dans la fonction pour récupérer les arguments de la liste.
// va_copy crée une copie d’une liste d’arguments dans son état actuel. Le paramètre src doit déjà être initialisé avec va_start ; il peut avoir été mis à jour avec des appels va_arg, mais il ne doit pas avoir été réinitialisé avec va_end. Le prochain argument à être récupéré par va_arg à partir de dest est le même que celui qui est récupéré à partir de src.
// Une fois tous les arguments récupérés, va_end réinitialise le pointeur vers NULL. va_end doit être appelé pour chaque liste d’arguments qui est initialisée avec va_start ou va_copy avant le retour de la fonction.

// cspdiuxX%

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
