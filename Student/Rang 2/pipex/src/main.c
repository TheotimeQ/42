/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/11 15:40:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{	
	
}

// open, close, read, write,
// malloc, free, perror,
// strerror, access, dup, dup2,
// execve, exit, fork, pipe,
// unlink, wait, waitpid

// ./pipex file1 cmd1 cmd2 file2
// •file1 et file2 sont des noms de fichier.
// •cmd1 et cmd2 sont des commandes shell avec leurs paramètres.

// Similaire à : < file1 cmd1 | cmd2 > file2

// ./pipex infile "ls -l" "wc -l" outfile
// < infile ls -l | wc -l > outfile

//  ./pipex infile "grep a1" "wc -w" outfile
//  < infile grep a1 | wc -w > outfile