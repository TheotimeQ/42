
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


//Structure pour les client 
typedef struct s_client
{

	int				fd;
	int				id;
	struct s_client	*next;

}					t_client;

//Global
t_client	*clients = NULL;
fd_set		current, read_set, write_set;
int			sockfd, g_id;
char		msg[200000], buff[200040];

//Erreur fatal 
void	fatal()
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	close(sockfd);
	exit(1);
}

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

//Recupere l'id du client associe au fd
int	get_id(int fd)
{
	t_client	*tmp = clients;

	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp->id);
		tmp = tmp->next;
	}
	return (-10);
}

//Envoi un message a tout les client qui on un autre fd
void	send_to_all(int fd)
{
	t_client	*tmp = clients;

	while (tmp)
	{
		if (tmp->fd != fd && FD_ISSET(tmp->fd, &write_set))
		{
			if (send(tmp->fd, buff, strlen(buff), 0) == -1)
				fatal();
		}
		tmp = tmp->next;
	}
}

//Fonctions qui clear toute la liste chainees ( a ajouter dans fatal et a la fin du programme )
// void    clear_client_liste()
// {

// }

//Add le client
void	add_client()
{
	t_client			*tmp = clients;
	t_client			*new;

	int					client;
	struct sockaddr_in	clientaddr;
	socklen_t			len = sizeof(clientaddr);

    //Accept la connection
	client = accept(sockfd, (struct sockaddr *)&clientaddr, &len);
	if (client == -1)
		fatal();

    //Previens les autres client
	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just arrived\n", g_id);
	send_to_all(client);

    //Ajoute a la liste de fd listen
	FD_SET(client, &current);

    //Allou le client
	new = malloc(sizeof(t_client));
	if (!new)
		fatal();

	new->fd = client;
	new->id = g_id++;
	new->next = NULL;

    //Si debut de liste
	if (!clients)
		clients = new;

    //Si fin de liste
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

//Remove le client de la liste chainer
void	rm_client(int fd)
{
	t_client	*to_del = NULL;
	t_client	*tmp = clients;
    
    //Envoi a tout le monde le message de quit
	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just left\n", get_id(fd));
	send_to_all(fd);

    //Delete le client 
	if (clients && clients->fd == fd)
	{
		to_del = clients;
		clients = clients->next;
	}
	else
	{
		while (tmp && tmp->next && tmp->next->fd != fd)
			tmp = tmp->next;

		if (tmp && tmp->next && tmp->next->fd == fd)
		{
			to_del = tmp->next;
			tmp->next = tmp->next->next;
		}
	}

    //Free le client
	if (to_del)
		free(to_del);

    //Ferme le descripteur
	FD_CLR(fd, &current);
	close(fd);
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
        //Tout les fd sont dans tout les set
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

                //Recupere le message bit par bit jusqu'au /n
				int	ret = 1;
				while (ret == 1 && msg[strlen(msg) - 1] != '\n')
				{   
					ret = recv(fd, msg + strlen(msg), 1, 0);

                    //Si on peut pas lire on stop
					if (ret <= 0)
						break ;
				}
            
                //Envoi le message
                if (msg[strlen(msg) - 1] == '\n')
                {
                    bzero(&buff, sizeof(buff));
                    sprintf(buff, "client %d: %s", get_id(fd), msg);
                    send_to_all(fd);
                    bzero(&msg, sizeof(msg));
                }

                //Si on arrive pas a lire, on deconnecte le client
				if (ret <= 0)
				{
					rm_client(fd);
					break ;
				}
			}
		}
	}

    FD_CLR(sockfd, &current);
    close(sockfd);

	return (0);
}

// gcc -Wall -Wextra -Werror mini_serv.c -o mini_serv ; ./mini_serv
