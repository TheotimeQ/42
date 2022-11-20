#include "../libft.h"

t_gbc   *gbc_init()
{
    t_gbc   *gbc;

    gbc = malloc(sizeof(t_gbc));
    if (!gbc)
        return (NULL);
    gbc->malloc_error = 0;
    gbc->gb_list = NULL;
    return (&gbc);
}

int main()
{
    t_gbc *gbc;

    gbc = gbc_init();

    //Malloc sans ajouter 
    char *str_1;
    str_1 = ft_malloc(10, sizeof(char*), gbc, 0);

    //Malloc en ajoutant
    char *str_2;
    str_2 = ft_malloc(10, sizeof(char*), gbc, 1);

    free(str_1)
    gbc_all_clear(gbc);
}