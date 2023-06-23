/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:36:15 by tochen            #+#    #+#             */
/*   Updated: 2023/06/21 19:36:20 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*result;

	result = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (result);
}

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

int	ft_strslen(int size, char **strs, char *sep)
{
	int	result;

	if (size == 0)
		return (0);
	result = 0;
	result += (size - 1) * ft_strlen(sep);
	while (size > 0)
	{
		result += ft_strlen(strs[size - 1]);
		size--;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	int		pos;

	result = malloc(sizeof(char) * (ft_strslen(size, strs, sep) + 1));
	if (!result)
		return (result);
	result[0] = 0;
	i = 0;
	pos = 0;
	while (i < size)
	{
		ft_strcpy(result + pos, strs[i]);
		pos += ft_strlen(strs[i]);
		if (i != size - 1)
		{
			ft_strcpy(result + pos, sep);
			pos += ft_strlen(sep);
		}
		i++;
	}
	return (result);
}
