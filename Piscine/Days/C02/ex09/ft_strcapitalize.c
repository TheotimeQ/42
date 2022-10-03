/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:40:39 by tquere            #+#    #+#             */
/*   Updated: 2022/07/10 11:40:41 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_word(char c)
{
	if (!(('A' <= c && c <= 'Z')
			|| ('0' <= c && c <= '9')
			|| ('a' <= c && c <= 'z')))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	search_word;

	search_word = 1;
	i = 0;
	while (str[i])
	{
		if (('A' <= str[i] && str[i] <= 'Z') && search_word == 1)
			search_word = 0;
		else if (('0' <= str[i] && str[i] <= '9') && search_word == 1)
			search_word = 0;
		else if (('A' <= str[i] && str[i] <= 'Z') && search_word == 0)
			str[i] = str[i] + 32;
		else if (('a' <= str[i] && str[i] <= 'z') && search_word == 1)
		{
			search_word = 0;
			str[i] = str[i] - 32 ;
		}
		else
			search_word = is_word(str[i]);
		i++;
	}
	return (str);
}
