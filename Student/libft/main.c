/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:49 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 14:48:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Header/libft.h"

//--------------- ANNEXES ---------------

// void print_tab(char **tab)
// {
//     int index;

//     index = 0;
//     while(tab[index] != NULL)
//     {
//         printf("|%s|\n",tab[index]);
//         index++;
//     }
// }

// void free_tab(char **tab)
// {
//     int index;

//     index = 0;
//     while(tab[index] != NULL)
//     {
//         free(tab[index]);
//         index++;
//     }
//     free(tab);
// }

// char    on_char1(unsigned int nb, char c)
// {
//     return (c + nb); 
// }

// void    on_char2(unsigned int nb, char *s)
// {
//     s[nb] = s[nb] + nb; 
// }

//--------------- Partie 1 ---------------

// isalpha
// int main()
// {  
// 	int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 65;
//     int e = '9';

//     printf ("%d\n", isalpha(a));
//     printf ("%d\n", isalpha(b));
//     printf ("%d\n", isalpha(c));
//     printf ("%d\n", isalpha(d));
//     printf ("%d\n\n", isalpha(e));

//     printf ("%d\n", ft_isalpha(a));
//     printf ("%d\n", ft_isalpha(b));
//     printf ("%d\n", ft_isalpha(c));
//     printf ("%d\n", ft_isalpha(d));
//     printf ("%d\n", ft_isalpha(e));

//     return (1);
// }

// isdigit
// int    main ()
// {
//     int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 65;
//     int e = '9';
//     printf ("%d\n", isdigit (a));
//     printf ("%d\n", isdigit (b));
//     printf ("%d\n", isdigit (c));
//     printf ("%d\n", isdigit (d));
//     printf ("%d\n\n", isdigit (e));

//     printf ("%d\n", ft_isdigit (a));
//     printf ("%d\n", ft_isdigit (b));
//     printf ("%d\n", ft_isdigit (c));
//     printf ("%d\n", ft_isdigit (d));
//     printf ("%d\n", ft_isdigit (e));
//     return (0);
// }

// isalnum
// int    main ()
// {
//     int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 65;
//     int e = '9';

//     printf ("%d\n", isalnum (a));
//     printf ("%d\n", isalnum (b));
//     printf ("%d\n", isalnum (c));
//     printf ("%d\n", isalnum (d));
//     printf ("%d\n\n", isalnum (e));

//     printf ("%d\n", ft_isalnum (a));
//     printf ("%d\n", ft_isalnum (b));
//     printf ("%d\n", ft_isalnum (c));
//     printf ("%d\n", ft_isalnum (d));
//     printf ("%d\n", ft_isalnum (e));
//     return (0);
// }

// isascii
// int    main ()
// {
//     int a = 5;
//     int b = 127;
//     int c = 543;
//     int d = '-';
//     printf("%d\n", isascii(a));
//     printf("%d\n", isascii(b));
//     printf("%d\n", isascii(c));
//     printf("%d\n\n", isascii(d));

//     printf("%d\n", ft_isascii(a));
//     printf("%d\n", ft_isascii(b));
//     printf("%d\n", ft_isascii(c));
//     printf("%d\n", ft_isascii(d));
// }

// isprint
// int    main ()
// {
//     int a = 'A';
//     int b = 67;
//     int c = '*';
//     int d = 2;
//     int e = 127;
//     printf ("%d\n", isprint (a));
//     printf ("%d\n", isprint (b));
//     printf ("%d\n", isprint (c));
//     printf ("%d\n", isprint (d));
//     printf ("%d\n\n", isprint (e));

//     printf ("%d\n", ft_isprint (a));
//     printf ("%d\n", ft_isprint (b));
//     printf ("%d\n", ft_isprint (c));
//     printf ("%d\n", ft_isprint (d));
//     printf ("%d\n", ft_isprint (e));
//     return (0);
// }

// ft_strlen
// int main()
// {   
//     char src[50] = "0123456";

//     printf("%ld",ft_strlen(src));
//     return (1);
// }

// memset
// int main () {
//    char str[50];
//    char str2[50];

//    strcpy(str,"This is string.h library function");
//    puts(str);

//    memset(str,'$',15);
//    puts(str);
   
//    strcpy(str2,"This is string.h library function");
//    ft_memset(str2, '$', 15);
//    puts(str2);
   
//    return(0);
// }

// bzero
// int main()
// {   
//     return (1);
// }

// memcpy
// int main()
// {   
//     return (1);
// }

// memmove
// int main()
// {   
//     return (1);
// }

// strlcpy
// int main()
// {   
//     return (1);
// }

// strlcat
// int main()
// {   
//     return (1);
// }

// toupper
// int main()
// {   
//     return (1);
// }

// tolower
// int main()
// {   
//     return (1);
// }

// strchr
// int main()
// {   
//     return (1);
// }

// strrchr
// int main()
// {   
//     return (1);
// }

// strncmp
// int main()
// {   
//     return (1);
// }

// memchr
// int main()
// {   
//     return (1);
// }

// memcmp
// int main()
// {   
//     return (1);
// }

// strnstr
// int main()
// {   
//     return (1);
// }

// atoi
// int main()
// {   
//     return (1);
// }

// calloc
// int main()
// {   
//     return (1);
// }

// strdup
// int main()
// {   
//     return (1);
// }

//--------------- Partie 2 ---------------

// ft_substr
// int main()
// {   
//     char src[50] = "J'aime les nouilles et les poneys";
//     char *out = ft_substr(src, 10, 50);

//     printf("%s",out);
//     free(out);

//     return (1);
// }

// ft_strjoin
// int main()
// {   
//     char pre[50] = "J'aime les nouilles ";
//     char suf[50] = "et les poneys";
//     char *out = ft_strjoin(pre, suf);

//     printf("%s",out);
//     free(out);

//     return (1);
// }

//ft_strtrim
// int main()
// {   
//     char src[50] = "1254618451    1451 J'aime les nouilles 1235481254";
//     char set[50] = "0123456789 ";
//     char *out = ft_strtrim(src, set);

//     printf("%s",out);
//     free(out);

//     return (1);
// }

// ft_split
// int main()
// {   
//     char src[100] = "  Coucou maman, j'aime les poneys   ";
//     char set = ' ';
//     char **out = ft_split(src, set);

//     print_tab(out);
//     free_tab(out);

//     return (1);
// }

//ft_itoa
// int main()
// {
//     printf("%s", ft_itoa(-45));
//     printf("\n");
//     printf("%s", ft_itoa(0));
//     printf("\n");
//     printf("%s", ft_itoa(45));
//     printf("\n");
//     printf("%s", ft_itoa(-2147483647));
//     printf("\n");
//     printf("%s", ft_itoa(2147483647));
// }

//ft_strmapi
// int main()
// {
//     char    str[50] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//     printf("%s",ft_strmapi(str, &on_char1));
// }

//ft_striteri
// int main()
// {
//     char    str[50] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
// 	printf("%s \n",str);
// 	ft_striteri(str, &on_char2);
//     printf("%s \n",str);
// }

//ft_putchar_fd
// int main()
// {	
// 	char c;

// 	c = 'q';
//     ft_putchar_fd(c,1);
// }

//ft_putstr_fd
// int main()
// {	
// 	char str[50] = "Les petits poneys sont tres mignons";
//     ft_putstr_fd(str,1);
// }

//ft_putendl_fd
// int main()
// {	
// 	char str[50] = "Les petits poneys sont tres mignons";
//     ft_putendl_fd(str,1);
// }

//ft_putnbr_fd
// int main()
// {	
//     ft_putnbr_fd(-2147483647,1);
//     printf("\n");
//     ft_putnbr_fd(2147483647,1);
//     printf("\n");
//     ft_putnbr_fd(5,1);
//     printf("\n");
// }