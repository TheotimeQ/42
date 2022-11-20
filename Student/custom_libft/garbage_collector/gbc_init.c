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