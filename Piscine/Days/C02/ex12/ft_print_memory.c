/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:41:41 by tquere            #+#    #+#             */
/*   Updated: 2022/09/19 15:50:15 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	convert_char(char *addr, int start, int printed)
{	
	int	digit;

	digit = (*(addr + start) >> 4) & 0xf;
	if (digit >= 10)
		digit = digit - 10 + 'a';
	else
		digit += '0' ;
	put_char(digit);
	printed++;
	digit = *(addr + start) & 0xf;
	if (digit >= 10)
		digit = digit - 10 + 'a';
	else
		digit += '0' ;
	put_char(digit);
	printed++;
	return (printed);
}

void	print_adresse(char *addr)
{
	int		digit_to_print;
	int		digit;
	char	*adress_char;

	adress_char = (char *)&addr;
	digit_to_print = 7;
	while (digit_to_print >= 0)
	{	
		digit = (adress_char[digit_to_print] >> 4) & 0xf;
		if (digit >= 10)
			digit = digit - 10 + 'a';
		else
			digit += '0' ;
		put_char(digit);
		digit = adress_char[digit_to_print] & 0xf;
		if (digit >= 10)
			digit = digit - 10 + 'a';
		else
			digit += '0' ;
		put_char(digit);
		digit_to_print--;
	}
	put_char(':');
	put_char(' ');
}

void	print_hexa_char(char *addr,	int start, int size)
{	
	int	j;
	int	printed;

	printed = 0;
	j = 0;
	while (j < 16 && j + start < size)
	{	
		printed = convert_char(addr, j + start, printed);
		if (printed % 32 == 0)
			put_char(' ');
		else if (printed % 4 == 0)
			put_char(' ');
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		printed = printed + 2 ;
		if (printed % 32 == 0)
			put_char(' ');
		else if (printed % 4 == 0)
			put_char(' ');
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;
	char			*addr_char;

	addr_char = addr;
	i = 0;
	while (i * 16 < size)
	{	
		print_adresse(addr + i * 16);
		print_hexa_char(addr, i * 16, size);
		j = 0;
		while (j < 16 && i * 16 + j < size)
		{
			if (' ' <= addr_char[i * 16 + j] && addr_char[i * 16 + j] <= '~' )
				put_char(addr_char[i * 16 + j]);
			else
				put_char('.');
			j++;
		}
		put_char('\n');
		i++;
	}
	return (addr);
}



int main()
{	
	char *string = "Bonjour , j'adore les chats et les poneys";
	ft_print_memory(string, 600);
}