/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:27:45 by tochen            #+#    #+#             */
/*   Updated: 2023/06/14 19:27:49 by tochen           ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	result;

	result = ft_strlen(src);
	while (*src && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
	return (result);
}
