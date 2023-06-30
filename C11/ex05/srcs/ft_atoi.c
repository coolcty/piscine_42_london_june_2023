/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:36:40 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 19:36:47 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	count_minus;
	int	nb;

	count_minus = 1;
	while (ft_isspace(*str))
		str++;
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			count_minus *= -1;
		str++;
	}
	nb = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		nb = nb * 10 + count_minus * (*str - '0');
		str++;
	}
	return (nb);
}
