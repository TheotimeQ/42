/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:19:28 by tquere            #+#    #+#             */
/*   Updated: 2023/03/02 14:02:12 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	test_diag(char *board, int i)
{	
	int	j;

	j = 0;
	while (j < 10 && board[j] != '!')
	{	
		if ((j < i && board[j] == board[i] - (i - j))
			|| (i < j && board[j] == board[i] - (j - i))
			|| (i < j && board[j] == board[i] + (j - i))
			|| (j < i && board[j] == board[i] + (i - j)))
			return (0);
		j++;
	}
	return (1);
}

int	test_comb(char *board)
{	
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{	
		j = 0;
		while (j < i)
		{
			if (board[i] == board[j] && board[i] != '!')
				return (0);
			j++;
		}
		if (test_diag(board, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	inc_comb(char *board, int n)
{	
	if (board[n] == '!')
	{
		board[n] = '0';
	}
	else if ('0' <= board[n] && board[n] < '9')
	{
		board[n] += 1;
	}
	else if (board[n] == '9')
	{
		board[n] = '!';
		n = inc_comb(board, n - 1);
	}
	return (n);
}

int	rec_find_comb(char *board, int n, int size)
{	
	if (n < 0)
		return (0);
	if (n == size)
	{	
		return (1);
	}
	else
	{	
		n = inc_comb(board, n);
	}
	if (test_comb(board) == 1)
	{	
		rec_find_comb(board, n + 1, size);
	}
	else
	{	
		rec_find_comb(board, n, size);
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	int				i;
	int				size;
	char			board[11];
	int				good_comb;
	int				n;

	good_comb = 0;
	size = 10;
	i = 0;
	n = 0;
	while (i < size)
		board[i++] = '!';
	board[size] = '\0';
	while (rec_find_comb(board, n, size) == 1 && good_comb < 724)
	{
		i = 0;
		while (i < 10)
		{
			write(1, &board[i++], 1);
		}
		write(1, "\n", 1);
		n = inc_comb(board, size - 1);
		good_comb += 1;
	}
	return (good_comb);
}

int main(void)
{
	printf("Solution : %d\n", ft_ten_queens_puzzle());
}