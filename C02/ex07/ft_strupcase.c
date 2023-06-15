/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:45:58 by tochen            #+#    #+#             */
/*   Updated: 2023/06/14 18:46:01 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*result;

	result = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str += 'A' - 'a';
		str++;
	}
	return (result);
}
