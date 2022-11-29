#include "push_swap_bonus.h"

static int    check_input(char *str)//, t_stack *a, t_stack *b)
{
    printf("%s",str);

    if (ft_strncmp(str,"sa",4) == 0)
        printf("sa");
    else if (ft_strncmp(str,"pa",4) == 0)
        printf("pa");
    else if (ft_strncmp(str,"ra",4) == 0)
        printf("ra");
    else if (ft_strncmp(str,"rra",4) == 0)
        printf("rra");
    else if (ft_strncmp(str,"sb",4) == 0)
        printf("sb");
    else if (ft_strncmp(str,"pb",4) == 0)
        printf("pb");
    else if (ft_strncmp(str,"rb",4) == 0)
        printf("rb");
    else if (ft_strncmp(str,"rrb",4) == 0)
        printf("rrb");
    else if (ft_strncmp(str,"ss",4) == 0)
        printf("ss");
    else if (ft_strncmp(str,"rr",4) == 0)
        printf("rr");
    else if (ft_strncmp(str,"rrr",4) == 0)
        printf("rrr");
    else
        return (1);
    return (0);
}

void listen_stdin(t_stack *a, t_stack *b)
{
    char    *str;
    char    buffer[2];
    int     i;

    i = 0;
    str = malloc( 5 * sizeof(char));
    ft_memset(str, 0, 4);
	while (read(0, buffer, 1) > 0)
	{   
        if (i > 4)
            break;

        str[i] = buffer[0];
        if (str[i] == '\n' || i == 4)
        {   
            str[4] = '\0';
            if (check_input(str) == 1) //, a, b) == 0)
            {
                write(1, "Error\n", 7);
                free(str);
                free_stack(a, b);
                return;
            }
            i = -1;
        }
        i++;
	}
    free(str);
    if (is_sorted( -1, a) == 1 && b->index == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3); 
}
