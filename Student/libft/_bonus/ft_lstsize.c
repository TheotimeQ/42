
#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int index;

    index = 1;
    while (lst->next != NULL)
    {
        lst = lst->next;
        index++;
    }
    return (index);
}
