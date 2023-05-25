//Given 
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

//A ajouter
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

fd_set		current, read_set, write_set;
int			sockfd;
int         g_id;
int			max_fd;

char		msg[200000];
char        buff[200040];
int    		clients[10000];

void    clear_sockets(void)
{
    int fd = 0;
    while (fd <= max_fd)
    {   
		if (clients[fd] > 0)
		{
        	FD_CLR(clients[fd], &current);
        	close(fd);
		}
        clients[fd] = -1;
        fd++;
    }
}

void	fatal()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));

    clear_sockets();

	FD_CLR(sockfd, &write_set);
	FD_CLR(sockfd, &read_set);
	FD_CLR(sockfd, &current);

	close(sockfd);
	
	exit(1);
}

int	get_id(int fd)
{
    if (clients[fd] >= 0)
	{
        return clients[fd];
	}
	return (-1);
}

void	send_to_all(int fd)
{
    int client_fd = 0;
    while (client_fd <= max_fd)
    {   
		if (client_fd != fd && FD_ISSET(client_fd, &write_set) && clients[client_fd] >= 0)
		{
			if (send(client_fd, buff, strlen(buff), 0) == -1)
				fatal();
		}
        client_fd++;
    }
}

void	add_client()
{
	int					client_fd;
	struct sockaddr_in	clientaddr;
	socklen_t			len = sizeof(clientaddr);

	client_fd = accept(sockfd, (struct sockaddr *)&clientaddr, &len);
	if (client_fd == -1)
		fatal();

	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just arrived\n", g_id);
	send_to_all(client_fd);

	FD_SET(client_fd, &current);

	clients[client_fd] = g_id++;

	if (client_fd > max_fd)
		max_fd = client_fd;
}

void	rm_client(int fd)
{
	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just left\n", get_id(fd));
	send_to_all(fd);

	FD_CLR(fd, &current);
	close(fd);

    clients[fd] = -1;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

	clear_sockets();

	struct sockaddr_in	servaddr;
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		fatal();

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
		fatal();

	if (listen(sockfd, 100) == -1)
		fatal();

	FD_ZERO(&current);
	FD_SET(sockfd, &current);
	bzero(&msg, sizeof(msg));

	max_fd = sockfd;
	g_id = 0;

	while (1)
	{
		read_set = write_set = current;

		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) == -1)
			continue ;

		for (int fd = 0; fd <= max_fd ; ++fd)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == sockfd)
				{
					add_client();
					break ;
				}

				int	ret = 1;
				while (ret == 1 && msg[strlen(msg) - 1] != '\n')
				{   
					ret = recv(fd, msg + strlen(msg), 1, 0);
					if (ret <= 0)
						break ;
				}
            
				if (ret <= 0)
				{
					rm_client(fd);
					break ;
				}

                if (msg[strlen(msg) - 1] == '\n')
                {
                    bzero(&buff, sizeof(buff));
                    sprintf(buff, "client %d: %s", get_id(fd), msg);
                    send_to_all(fd);
                    bzero(&msg, sizeof(msg));
                }
			}
		}
	}

    clear_sockets();

    FD_CLR(sockfd, &write_set);
	FD_CLR(sockfd, &read_set);
	FD_CLR(sockfd, &current);

    close(sockfd);

	return (0);
}