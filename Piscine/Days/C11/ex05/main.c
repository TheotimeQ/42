/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:49:46 by tquere            #+#    #+#             */
/*   Updated: 2022/07/20 06:49:50 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	convert_print(int nb_long, int len_base, char *base);
int		add_op(int a, int b);
int		minus_op(int a, int b);
int		mult_op(int a, int b);
int		div_op(int a, int b);
int		mod_op(int a, int b);
int		ft_atoi(char *str);

int	get_op_index(char op, char *charset)
{	
	int	index;

	index = 0;
	if (op == '%')
		return (4);
	while (index < 4)
	{
		if (op == charset[index])
			return (index);
		index++;
	}
	return (-1);
}

int	check_cond(int index_op, int int_1, int int_2)
{
	if (index_op == -1)
	{
		ft_putstr("0\n");
		return (1);
	}
	if (index_op == 3 && int_2 == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (index_op == 3 && int_2 == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	if (index_op == 3 && int_2 > int_1)
	{
		ft_putstr("0\n");
		return (1);
	}
	return (0);
}

void	init_tab(int (**ptr)(int, int))
{
	ptr[0] = &add_op;
	ptr[1] = &minus_op;
	ptr[2] = &mult_op;
	ptr[3] = &div_op;
	ptr[4] = &mod_op;
}

void	print_nb(int int_1, int int_2, char **argv, int (**ptr)(int, int))
{	
	int		index_op;

	index_op = get_op_index(argv[2][0], "+-*/%");
	if (check_cond(index_op, int_1, int_2))
		return ;
	int_1 = (*ptr[index_op])(int_1, int_2);
	if (int_1 < 0)
	{
		ft_putstr("-");
		int_1 *= -1;
	}
	if (int_1 == 0)
	{
		ft_putstr("0\n");
		return ;
	}
	convert_print(int_1, 10, "0123456789");
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{	
	int		int_1;
	int		int_2;
	int		(*ptr[5])(int, int);

	if (argc != 4)
		return (0);
	init_tab(ptr);
	int_1 = ft_atoi(argv[1]);
	int_2 = ft_atoi(argv[3]);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0\n");
		return (0);
	}
	print_nb(int_1, int_2, argv, ptr);
	return (0);
}
