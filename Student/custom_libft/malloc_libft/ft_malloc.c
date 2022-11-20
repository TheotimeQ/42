#include "../libft.h"

void	*ft_malloc(size_t count, size_t size, t_gbc *gdb);
{
	void		*mem;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

//SI MALLOC ERRROR RETURN ERROR 

//SINON AJOUTE A LA LISTE CHAINE DU GBC LE POINTEUR SUR MALLOC