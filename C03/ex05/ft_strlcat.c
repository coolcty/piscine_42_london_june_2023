/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:51:54 by tochen            #+#    #+#             */
/*   Updated: 2023/06/15 23:52:02 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	result;
	unsigned int	l_dest;
	unsigned int	l_src;

	result = 0;
	l_dest = 0;
	l_src = ft_strlen(src);
	while (*dest && result < size)
	{
		dest++;
		result++;
		l_dest++;
	}
	if (*dest)
		return (l_dest + l_src);
	while (*src && result + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		result++;
	}
	*dest = 0;
	return (l_dest + l_src);
}
