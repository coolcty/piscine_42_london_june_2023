/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:29:56 by tochen            #+#    #+#             */
/*   Updated: 2023/06/16 16:29:57 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == ' ' || (c <= 13 && c >= 9));
}

int	ft_isdigit(char c)
{
	return (c <= '9' && c >= '0');
}

int	ft_atoi(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign*= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
