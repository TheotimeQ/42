/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:18 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 15:52:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_gbc	*gbc_init(void)
{
	t_gbc	*gbc;

	gbc = malloc(sizeof(t_gbc));
	if (!gbc)
		return (NULL);
	gbc->malloc_error = 0;

	char *content1 = "Les segfault c'est pour les zozos";
    t_list 	*list1 = ft_lstnew((void *)content1);

	gbc->gb_list = &list1 ;

	return (gbc);
}

int	main()
{
	t_gbc	*gbc;

	gbc = gbc_init();

	gbc_show(gbc);

	// char *str_1;
	// str_1 = ft_malloc(10, sizeof(char *), gbc, 0);
	// free(str_1);

	// char *str_2;
	// str_2 = ft_malloc(10, sizeof(char *), gbc, 1);
	
	char *str_3;
	str_3 = ft_malloc(10, sizeof(char *), gbc, 1);

	char *str_4;
	str_4 = ft_malloc(10, sizeof(char *), gbc, 1);

	// gbc_show(gbc);
	// gbc_all_clear(gbc);
	check_leaks();
}
