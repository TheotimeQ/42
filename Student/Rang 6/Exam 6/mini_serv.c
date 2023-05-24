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

//Global
t_client	*clients = NULL;
fd_set		current, read_set, write_set;
int			sockfd, g_id;
char		msg[200000], buff[200040];

//Structure pour les client 
typedef struct s_client
{
	int				fd;
	int				id;
	struct s_client	*next;
} t_client;

//Parcour les client pour choper le plus gros fd 
int	get_max_fd()
{
	int			max_fd = sockfd;
	t_client	*tmp = clients;

	while (tmp)
	{
		if (tmp->fd > max_fd)
			max_fd = tmp->fd;
		tmp = tmp->next;
	}
	return (max_fd);
}

//Erreur fatal 
void	fatal()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	close(sockfd);
	exit(1);
}

int	main(int argc, char **argv)
{

    //Manque port
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

    //Setup struc address
	struct sockaddr_in	servaddr;
	bzero(&servaddr, sizeof(servaddr));

    //Setup adress
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));

    //Creer socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		fatal();

    //Bind la socket
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
		fatal();

    //Ecoute sur la socket
	if (listen(sockfd, 100) == -1)
		fatal();

    //Reset le set
	FD_ZERO(&current);
    
    //Mets le socket server dans current
	FD_SET(sockfd, &current);

    //Init malloc message
	bzero(&msg, sizeof(msg));

	while (1)
	{
        //Mets le socket du server dans read et write
		read_set = write_set = current;

        //Si aucun event on continue a attendre les events
		if (select(get_max_fd() + 1, &read_set, &write_set, NULL, NULL) == -1)
			continue ;

        //Parcours tout les fd connus
		for (int fd = 0; fd <= get_max_fd(); ++fd)
		{
            
            //Si fd pret en lecture 
			if (FD_ISSET(fd, &read_set))
			{
                //Si retour = fd du server, on ajoute un client
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
				extract_msg(fd);
			}

            //Si fd pas pret en lecture on fait rien 
		}
	}
	return (0);
}

// gcc -Wall -Wextra -Werror mini_serv.c -o mini_serv ; ./mini_serv