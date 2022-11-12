/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:46:18 by tquere            #+#    #+#             */
/*   Updated: 2022/11/12 14:52:46 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"


int	main(void)
{	
	printf("%d  |\n",ft_printf("%9.5s", "Coucou"));
	printf("%d  |\n",printf("%9.5s", "Coucou"));

	return (0);
}

// http://manpagesfr.free.fr/man/man3/printf.3.html
// https://learn.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170

// Gérez toute combinaison des drapeaux suivants : ’-0.’ ainsi que la largeur minimale du champ avec toutes les conversions.
// Gérez tous les drapeaux suivants : ’# +’ (Oui, l’espace est un drapeau valide)

// . Precision :
// printf( "%.*f", 3, 3.14159265 ); /* 3.142 output */
// printf( "%.3f", 3.14159265 ); /* 3.142 output */
// printf( "%.0d", 0 ); /* No characters output */

// # prefice
// Lorsqu’il est utilisé avec le oformat , xou X , l’indicateur # 
// utilise 0, 0xou 0X, respectivement, pour préfixer toute valeur de sortie différente de zéro.

// Utilisez un signe (+ ou -) pour préfixer la valeur de sortie s’il s’agit d’un type signé.