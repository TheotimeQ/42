/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:55:20 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/18 19:16:49 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_list(t_stack *a, t_stack *b)
{	
	int i;

	printf("\n|a    b\n|\n");
	i = a->index - 1;
	if (a->index < b->index)
		i = b->index - 1;
	while (i >= 0)
	{	
		if (i < a->index)
			printf("|%d    ",a->data[i]);
		else
			printf("|     ");
		if (i < b->index)
			printf("%d    ",b->data[i]);
		printf("\n");
		i--;
	}
	printf("\n");
}

static int	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
    int     	i;

	b->index = 0;
	a->index = 0;
	if (argc == 2)
	{	
		argv = ft_split(argv[1],' ');
		argc = 0;
		i = 0;
		while (argv[i++])
			argc++;
		i = argc - 1;
		a->data = malloc(sizeof(int) * argc);
		if (a->data == NULL)
			exit(1);
		while (i >= 0)
			push_stack(a, ft_atoi(argv[i--]));
		free_tab(argv,argc);
	}
	else
	{	
		a->data = malloc(sizeof(int) * argc);
		if (a->data == NULL)
			exit(1);
		i = argc - 1;
		while (i > 0)
			push_stack(a, ft_atoi(argv[i--]));
	}
	b->data = malloc(sizeof(int) * argc);
	if (b->data == NULL)
		exit(1);
	return (argc);
}

static int	check_args(int argc ,char **argv)
{
	int 	i;
	
	i = 1;
	while (i < argc)
	{	
		if(ft_isnum(argv[i]) == 0)
			return (1);
		if(ft_atoi(argv[i]) < INT32_MIN || INT32_MAX < ft_atoi(argv[i]) )
			return (1);
		i++;
	}
	return (0);
}

static void	free_stack(t_stack *a, t_stack *b)
{
	free(a->data);
	free(b->data);
	free(a);
	free(b);
}

int main(int argc, char **argv)
{	
	t_stack *a;
	t_stack *b;
	int		nb_value;

    if (argc == 1)
	{
		ft_putstr_fd("Error\n",2);
        return (1);
	}
	if (check_args(argc, argv))
	{
		ft_putstr_fd("Error\n",2);
        return (1);
	}
	a = malloc(sizeof(t_stack));
	if (a == NULL)
		return (1);
	b = malloc(sizeof(t_stack));
	if (b == NULL)
	{
		free(a);
		return (1);
	}
    nb_value = init_stack(a, b, argc, argv);
	if (ft_is_double(a->data, nb_value))
	{
		ft_putstr_fd("Error\n",2);
		free_stack(a, b);
        return (1);
	}	
	resolve_push_swap(a, b);
	free_stack(a, b);
    return (0);
}