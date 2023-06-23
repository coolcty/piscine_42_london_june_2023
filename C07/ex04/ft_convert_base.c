/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:27:46 by tochen            #+#    #+#             */
/*   Updated: 2023/06/21 22:27:48 by tochen           ###   ########.fr       */
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

int	ft_valid_base(char *str)
{
	char	stat[256];
	int		i;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (i < 256)
	{
		stat[i] = 0;
		i++;
	}
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		if (*str == ' ' || (*str <= 13 && *str >= 9))
			return (0);
		if (stat[(unsigned char)*str] == 1)
			return (0);
		stat[(unsigned char)*str] = 1;
		str++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c <= 13 && c >= 9));
}

int	ft_process_base_table(unsigned char *base_to_num, char *base)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		base_to_num[i] = 255;
		i++;
	}
	i = 0;
	while (*base)
	{
		base_to_num[(unsigned char)*base] = i;
		i++;
		base++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned char	base_to_num[256];
	int				i;
	long long		result;
	int				sign;

	result = 0;
	sign = 1;
	if (!ft_valid_base(base))
		return (0);
	i = ft_process_base_table(base_to_num, base);
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (base_to_num[(unsigned int)*str] != 255)
	{
		result *= i;
		result += base_to_num[(unsigned int)*str];
		str++;
	}
	return (result * sign);
}
