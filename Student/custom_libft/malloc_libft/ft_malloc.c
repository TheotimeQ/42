#include "../libft.h"

void	*ft_malloc(size_t count, size_t size, t_gbc *gbc, size_t add_gbc)
{
	void		*mem;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
    if (!gbc)
        return (NULL);
	mem = malloc(count * size);
	if (mem == NULL)
    {
        gbc->malloc_error = 1;
		return (NULL);
    }
    if(add_gbc)
        gbc_add(gbc, mem);
	return (mem);
}
