/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:24:04 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 06:22:44 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0 ;
	while (i < n && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = 0;
	while (dest[len_dest])
	{
		len_dest++;
	}
	len_src = 0;
	while (len_src < nb)
	{
		dest[len_dest + len_src] = src[len_src];
		len_src++;
	}
	dest[len_dest + len_src] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i <= n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	init_str(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		str[i] = 0;
		i++;
	}
	str[0] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
