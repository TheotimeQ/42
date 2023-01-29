/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:18 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 14:06:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_gbc	*gbc_init(void)
{
	t_gbc	*gbc;

	gbc = malloc(sizeof(t_gbc));
	if (gbc == NULL)
		return (NULL);
	gbc->malloc_error = 0;
	return (gbc);
}

static	void	gbc_free(void *str, t_gbc *gbc)
{	
	t_list	*last_elem;
	t_list	*current_elem;

	if (!gbc->gbc_list)
		return ;
	current_elem = *(gbc->gbc_list);
	if (current_elem == NULL)
		return ;
	if (str == current_elem->content)
	{	
		*gbc->gbc_list = current_elem->next;
		free(current_elem->content);
		free(current_elem);
		return ;
	}
	last_elem = current_elem;
	while (current_elem->next != NULL)
	{	
		if (str == current_elem->content)
		{	
			last_elem->next = current_elem->next;
			free(current_elem->content);
			free(current_elem);
			return ;
		}
		last_elem = current_elem;
		current_elem = current_elem->next;
	}
	free(str);
}

int	main()
{
	t_gbc	*gbc;

	gbc = gbc_init();

	t_list	*start_list;
	start_list = NULL;
	gbc->gbc_list = &start_list ;
	printf("LIST = %p\n", gbc->gbc_list);
	printf("first = %p\n", *(gbc->gbc_list));



	gbc_show(gbc);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);

	char *str_1;
	str_1 = ft_malloc(10, sizeof(char *), gbc, 1);
	printf("\nSTR 1 : %p\n",str_1);

	ft_malloc(10, sizeof(char), gbc, 1);

	char *str_2;
	str_2 = malloc(300);
	printf("\nSTR 2 : %p\n",str_2);

	ft_malloc(10, sizeof(char), gbc, 1);

	char *str_3;
	str_3 = ft_malloc(10, sizeof(char *), gbc, 1);
	printf("\nSTR 2 : %p\n",str_3);

	ft_malloc(10, sizeof(char), gbc, 1);

	gbc_show(gbc);

	// gbc_free(str_1, gbc);
	// gbc_free(str_3, gbc);
	gbc_free(str_2, gbc);
	
	gbc_show(gbc);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	ft_malloc(10, sizeof(char), gbc, 1);
	gbc_show(gbc);

	gbc_all_clear(gbc);
	gbc_show(gbc);
	free(gbc);
}
