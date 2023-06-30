/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:38:40 by tochen            #+#    #+#             */
/*   Updated: 2023/06/23 02:38:42 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	ft_init_cst(char *cs_table, char *charset)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		cs_table[i] = 0;
		i++;
	}
	while (*charset)
	{
		cs_table[(unsigned char)(*charset)] = 1;
		charset++;
	}
}

int	ft_strlen_sep(char *str, char *cs_table)
{
	int	result;

	result = 0;
	while (*str && cs_table[(unsigned char)*str] == 0)
	{
		result++;
		str++;
	}
	return (result);
}

void	ft_str_len_cpy(char *dest, char *src, unsigned int len)
{
	while (len > 0)
	{
		*dest = *src;
		dest++;
		src++;
		len--;
	}
	*dest = 0;
}

int	ft_count_size(char *str, char *cs_table)
{
	int	result;

	result = 0;
	while (*str)
	{
		while (*str && cs_table[(unsigned char)(*str)])
		{
			str++;
		}
		if (*str && !cs_table[(unsigned char)(*str)])
			result++;
		while (*str && !cs_table[(unsigned char)(*str)])
		{
			str++;
		}
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	cs_table[256];
	char	**result;
	int		ar_sz;
	int		i;
	int		sz;

	ft_init_cst(cs_table, charset);
	ar_sz = ft_count_size(str, cs_table);
	result = malloc(sizeof(char *) * (ar_sz + 1));
	if (!result)
		return (result);
	result[ar_sz] = 0;
	i = 0;
	while (i < ar_sz)
	{
		while (*str && cs_table[(unsigned char)*str] == 1)
			str++;
		sz = ft_strlen_sep(str, cs_table);
		result[i] = malloc(sizeof(char) * (sz + 1));
		ft_str_len_cpy(result[i], str, sz);
		str += sz;
		i++;
	}
	return (result);
}
