
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

# include <stdio.h>

# include "libft/libft.h"

int main(void)
{	
	int 	fd;
	char 	*str;

	int 	fd_pipe[2];

	// fd = open("test.txt", O_RDONLY);
	// str = get_next_line(fd);
	// printf("FILE : %d \n",fd);
	// printf("%s", str);

	pipe(fd_pipe);



	write(fd);



	close(fd);
}