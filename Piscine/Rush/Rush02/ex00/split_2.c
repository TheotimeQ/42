/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:58:40 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 21:59:04 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include "struct.h"

char		*init_str(char *str, int len);

t_dict	search_key_2(t_dict dict, char *str)
{
	int	idx;
	int	end;
	int	start;

	idx = dict.index;
	start = idx;
	while ('0' <= str[idx] && str[idx] <= '9')
		idx++;
	end = idx;
	free(dict.key);
	dict.key = malloc(sizeof(char) * (idx - start + 1));
	dict.key = init_str(dict.key, idx - start + 1);
	idx = start;
	while (idx < end)
	{
		dict.key[idx - start] = str[idx];
		idx++;
	}
	dict.index = idx;
	dict.key[end] = '\0';
	dict.key = dict.key;
	return (dict);
}

t_dict	search_key(t_dict dict, char *str)
{
	int	idx;
	int	end;
	int	start;

	start = -1;
	end = -1;
	idx = 0;
	while (' ' == str[idx])
		idx++;
	while ('+' == str[idx] || '-' == str[idx])
		idx++;
	if ('0' <= str[idx] && str[idx] <= '9')
	{
		dict.index = idx;
		dict = search_key_2(dict, str);
	}
	else
		dict.error = 1;
	return (dict);
}

t_dict	search_value_2(t_dict dict, char *str)
{
	int	idx;
	int	end;
	int	start;

	start = -1;
	end = -1;
	idx = dict.index;
	if (' ' < str[idx] && str[idx] <= '~')
	{
		start = idx;
		while (' ' <= str[idx] && str[idx] <= '~')
			idx++;
		end = idx;
		free(dict.value);
		dict.value = malloc(sizeof(char) * (idx - start + 1));
		dict.value = init_str(dict.value, idx - start + 1);
		idx = start;
		while (idx < end)
		{	
			dict.value[idx - start] = str[idx];
			idx++;
		}
		dict.value[end + 1] = '\0';
	}
	return (dict);
}

t_dict	search_value(t_dict dict, char *str)
{	
	int	idx;

	idx = dict.index;
	while (' ' != str[idx] && ':' != str[idx])
		idx++;
	while (' ' == str[idx])
		idx++;
	if (':' == str[idx])
	{
		idx++;
		while (' ' == str[idx])
			idx++;
		if (str[idx] == '\n')
			dict.error = 1;
		dict.index = idx;
		dict = search_value_2(dict, str);
	}
	else
		dict.error = 1;
	return (dict);
}
