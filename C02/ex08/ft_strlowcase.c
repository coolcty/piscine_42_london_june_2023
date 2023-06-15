/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:49:27 by tochen            #+#    #+#             */
/*   Updated: 2023/06/14 18:49:30 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*result;

	result = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str -= 'A' - 'a';
		str++;
	}
	return (result);
}
