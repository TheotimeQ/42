
#include "../Header/libft.h"

size_t ft_strlen(const char *s){
    unsigned int    index;

    index = 0;
    while(s[index])
        index++;
    return (index);
}