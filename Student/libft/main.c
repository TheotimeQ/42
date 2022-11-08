/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:49 by tquere            #+#    #+#             */
/*   Updated: 2022/11/08 11:45:57 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "Header/libft.h"

void print_tab(char **tab)
{
    int index;

    index = 0;
    while(tab[index] != NULL)
    {
        printf("|%s|\n",tab[index]);
        index++;
    }
}

void free_tab(char **tab)
{
    int index;

    index = 0;
    while(tab[index] != NULL)
    {
        free(tab[index]);
        index++;
    }
    free(tab);
}

//--------------- Partie 1 ---------------

// ft_strlen
// int main()
// {   
//     char src[50] = "0123456";

//     printf("%ld",ft_strlen(src));
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
//     char src[100] = "11111111111111111111";
//     char set = '1';
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