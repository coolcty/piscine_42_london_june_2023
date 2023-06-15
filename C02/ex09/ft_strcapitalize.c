/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:51:01 by tochen            #+#    #+#             */
/*   Updated: 2023/06/14 18:51:03 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'));
}

int	ft_isdigit(char c)
{
	return (c <= '9' && c >= '0');
}

int	ft_isalnum(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

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

char	*ft_strcapitalize(char *str)
{
	char	*result;
	int		pre;

	result = str;
	pre = 0;
	str = ft_strlowcase(str);
	while (*str)
	{
		if (!pre && ft_isalpha(*str))
			*str += 'A' - 'a';
		pre = ft_isalnum(*str);
		str++;
	}
	return (result);
}
