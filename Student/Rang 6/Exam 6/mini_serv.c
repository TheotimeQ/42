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

#define MAX_MSG     200000
#define MAX_BUFF    200040
#define MAX_CLIENTS 10000

typedef struct s_client
{

	int		fd;
	int		id;

}   t_client;

fd_set		current, read_set, write_set;
int			sockfd, g_id;
int         g_id;
char		msg[MAX_MSG];
char        buff[MAX_BUFF];
t_client    *clients[MAX_CLIENTS];

void    clear_clients(void)
{
    int i = 0;
    while (clients[i])
    {   
        FD_CLR(clients[i]->fd, &current);
        close(clients[i]->fd);
        free(clients[i]);
        clients[i] = NULL;
        i++;
    }
}

void	fatal()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
    clear_clients();
	close(sockfd);
	exit(1);
}

int	get_max_fd()
{
    int	max_fd = sockfd;

    int i = 0;
    while (clients[i])
    {   
        if (clients[i]->fd > max_fd)
			max_fd = clients[i]->fd;
        i++;
    }
    return (max_fd);
}

int	get_id(int fd)
{
    if (clients[fd - sockfd - 1])
    {
        return clients[fd - sockfd - 1]->id;
    }

	return (-10);
}

void	send_to_all(int fd)
{
    int i = 0;
    while (clients[i])
    {   
        t_client *client = clients[i];
        if (client->fd != fd && FD_ISSET(client->fd, &write_set))
		{
			if (send(client->fd, buff, strlen(buff), 0) == -1)
				fatal();
		}
        i++;
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

	t_client *new = malloc(sizeof(t_client));
	if (!new)
		fatal();

	FD_SET(client_fd, &current);
	new->fd = client_fd;
	new->id = g_id++;
    clients[client_fd - sockfd - 1] = new;
}

void	rm_client(int fd)
{
	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just left\n", get_id(fd));
	send_to_all(fd);

    if (clients[fd])
	    free(clients[fd]);

	FD_CLR(fd, &current);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

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

	while (1)
	{
		read_set = write_set = current;

		if (select(get_max_fd() + 1, &read_set, &write_set, NULL, NULL) == -1)
			continue ;

		for (int fd = 0; fd <= get_max_fd(); ++fd)
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
            
                if (msg[strlen(msg) - 1] == '\n')
                {
                    bzero(&buff, sizeof(buff));
                    sprintf(buff, "client %d: %s", get_id(fd), msg);
                    send_to_all(fd);
                    bzero(&msg, sizeof(msg));
                }

				if (ret <= 0)
				{
					rm_client(fd);
					break ;
				}
			}
		}
	}

    clear_clients();
    FD_CLR(sockfd, &current);
    close(sockfd);

	return (0);
}