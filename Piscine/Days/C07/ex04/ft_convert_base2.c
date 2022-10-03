/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:24:53 by tquere            #+#    #+#             */
/*   Updated: 2022/07/28 19:45:08 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_from(char c, char *str);

int	verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (ft_char_is_from(base[i], "+- \t\v\n\r\f"))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

char	*ft_evac_char_from_base(char *str, char *base)
{
	int	i;
	int	j;
	int	isbase;

	i = 0;
	j = 0;
	isbase = 1;
	while (str[i] && isbase)
	{
		isbase = 0;
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j] && isbase == 0)
			{
				isbase = 1;
				i++;
			}
			j++;
		}	
	}
	return (str + i);
}

char	*ft_evac_signs(char *str, int *res)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*res = *res * -1;
		i++;
	}
	return (str + i);
}

int	ft_translate(char *str, char *base, int *res, int szbase)
{
	int	i;
	int	j;
	int	mem;

	i = 0;
	j = 0;
	mem = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != base[j] && base[j])
			j++;
		if (j == szbase)
			return (mem * *res);
		mem = mem * szbase + j;
		i++;
	}
	*res = *res * mem;
	return (*res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	*ptres;
	int	rslt;
	int	szbase;

	szbase = 0;
	while (base[szbase])
		szbase++;
	if (!(verif_base(base)))
		return (0);
	rslt = 1;
	ptres = &rslt;
	str = ft_evac_char_from_base(str, "\t\n\v\f\r ");
	str = ft_evac_signs(str, ptres);
	*ptres = ft_translate(str, base, ptres, szbase);
	return (*ptres);
}
