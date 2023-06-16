/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:40:12 by tochen            #+#    #+#             */
/*   Updated: 2023/06/15 19:40:14 by tochen           ###   ########.fr       */
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

void	ft_get_next(int *next, char *s)
{
	int	j;
	int	i;

	j = -1;
	next[0] = j;
	i = 1;
	while (i < ft_strlen(s))
	{
		while (j >= 0 && s[i] != s[j + 1])
		{
			j = next[j];
		}
		if (s[i] == s[j + 1])
		{
			next[i] = j;
		}
		i++;
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	next[10000];
	int	i;
	int	j;

	if (!*to_find)
		return (str);
	ft_get_next(next, to_find);
	j = -1;
	i = 0;
	while (i < ft_strlen(str))
	{
		while (j >= 0 && str[i] != to_find[j + 1])
			j = next[j];
		if (str[i] == to_find[j + 1])
			j++;
		if (j == ft_strlen(to_find) - 1)
			return (str + i - ft_strlen(to_find) + 1);
		i++;
	}
	return (0);
}
