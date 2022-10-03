/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:02:51 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 22:02:52 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

char		*init_str(char *str, int len);
t_dict		search_key(t_dict dict, char *str);
t_dict		search_value(t_dict dict, char *str);

t_dict	split(t_dict dict, char *str)
{	
	dict = search_key(dict, str);
	if (dict.error == 0)
	{
		dict = search_value(dict, str);
	}
	return (dict);
}
