/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbc_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:13:34 by tquere            #+#    #+#             */
/*   Updated: 2022/11/20 15:43:39 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Stocker le pointeur 
static t_list	*ft_gdb_new(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

static void	gbc_ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	gbc_add(void *content, t_gbc *gbc)
{
	t_list	*new_garbage;

	new_garbage = ft_gdb_new(content);
	if (new_garbage == NULL)
	{
		gbc->malloc_error = 1;
		return ;
	}

	gbc_ft_lstadd_front(gbc->gb_list, new_garbage);

// ft_lstadd_front
// int main()
// {	
//     char *content1 = "J'aime les chatons malades";
//     char *content2 = "Non je ne metterai pas les include Valentin <3";

//     t_list 	*list1 = ft_lstnew((void *)content1);
//     t_list 	*list2 = ft_lstnew((void *)content2);
//     ft_lstadd_front(&list1, list2);
//     print_list(list2);
//     free(list2);
//     free(list1);
// }

	// gbc->gb_list       **list = NULL

}














	// if (!gbc->gb_list)
	// {
	// 	gbc->gb_list = &new_garbage;
	// 	printf("1 - 1 : %p \n", *(gbc->gb_list));
	// }
	// else
	// {	
	// 	printf("1 - 2 : %p \n", *(gbc->gb_list));
	// 	new_garbage->next = *(gbc->gb_list);
	// 	gbc->gb_list = &new_garbage;
	// 	printf("2 - 1 : %p \n", *(gbc->gb_list));
	// }
