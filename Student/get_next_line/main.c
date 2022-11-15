/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:30:02 by tquere            #+#    #+#             */
/*   Updated: 2022/11/15 17:46:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("LINE : %s", get_next_line(fd));
	printf("LINE : %s", get_next_line(fd));
	printf("LINE : %s", get_next_line(fd));
	return (0);
}
