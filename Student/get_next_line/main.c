/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:30:02 by tquere            #+#    #+#             */
/*   Updated: 2022/11/17 09:21:02 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

// https://github.com/Tripouille/gnlTester.git

int	main(void)
{
	int		fd_1;
	int		fd_2;
	char 	*str;

	fd_1 = open("test1.txt", O_RDONLY);
	fd_2 = open("test2.txt", O_RDONLY);

	str = get_next_line(fd_2);
	printf("FD : %d  |  %s", fd_2, str);
	free(str);

	str = get_next_line(fd_2);
	printf("FD : %d  |  %s", fd_2, str);
	free(str);

	str = get_next_line(fd_2);
	printf("FD : %d  |  %s", fd_2, str);
	free(str);

	str = get_next_line(fd_1);
	printf("FD : %d  |  %s", fd_1, str);
	free(str);

	str = get_next_line(fd_1);
	printf("FD : %d  |  %s", fd_1, str);
	free(str);

	str = get_next_line(fd_1);
	printf("FD : %d  |  %s", fd_1, str);
	free(str);

	str = get_next_line(fd_2);
	printf("FD : %d  |  %s", fd_2, str);
	free(str);

	close(fd_1);
	close(fd_2);

	return (0);
}
