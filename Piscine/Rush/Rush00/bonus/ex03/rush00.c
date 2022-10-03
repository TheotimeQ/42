/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:24:15 by tquere            #+#    #+#             */
/*   Updated: 2022/07/09 13:31:28 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#define LONGUEUR_CARACT "B"
#define LARGEUR_CARACT "B"
#define CORNER_CARACT_1 "A"
#define CORNER_CARACT_2 "C"
#define CORNER_CARACT_3 "A"
#define CORNER_CARACT_4 "C"
#define SPACE_CARACT " "

void	ft_putchar(char *str);

void	print_line(int L, char *start_c, char *mid_c, char *end_c)
{
	int	i ;

	if (L > 1)
	{
		ft_putchar(start_c);
		i = 0 ;
		while (i < L - 2)
		{
			ft_putchar(mid_c);
			i++ ;
		}
		ft_putchar(end_c);
		ft_putchar("\n");
	}
	else
	{
		ft_putchar(start_c);
		ft_putchar("\n");
	}
}

void	rush(int L, int l)
{
	int	i;

	print_line(L, CORNER_CARACT_1, LARGEUR_CARACT, CORNER_CARACT_2);
	i = 0 ;
	while (i < l - 2)
	{
		print_line(L, LONGUEUR_CARACT, SPACE_CARACT, LONGUEUR_CARACT);
		i++;
	}
	if (l > 1)
	{
		print_line(L, CORNER_CARACT_3, LARGEUR_CARACT, CORNER_CARACT_4);
	}
}
