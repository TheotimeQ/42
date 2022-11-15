/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:30:02 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 21:14:39 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char 	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("LINE : %s", str);
	free(str);

	str = get_next_line(fd);
	printf("LINE : %s", str);
	free(str);

	str = get_next_line(fd);
	printf("LINE : %s", str);
	free(str);

	str = get_next_line(fd);
	printf("LINE : %s", str);
	free(str);

	str = get_next_line(fd);
	printf("LINE : %s", str);
	free(str);
	
	return (0);
}
