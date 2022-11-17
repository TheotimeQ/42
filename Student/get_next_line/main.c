/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:30:02 by tquere            #+#    #+#             */
/*   Updated: 2022/11/17 16:37:40 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

// https://github.com/Tripouille/gnlTester.git

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("gnlTester/files/43_no_nl", O_RDWR);
	str = get_next_line(fd);
	printf("\n     OUTPUT:%s\n", str);
	free(str);

	str = get_next_line(fd);
	printf("\n     OUTPUT:%s\n", str);
	free(str);

	str = get_next_line(fd);
	printf("\n     OUTPUT:%s\n", str);
	free(str);

	str = get_next_line(fd);
	printf("\n     OUTPUT:%s\n", str);
	free(str);
	// while (str != NULL)
	// {
	// 	str = get_next_line(fd);
	// 	printf("\n STR = %s", str);
	// 	free(str);
	// }
	close(fd); 
	return (0);
}
