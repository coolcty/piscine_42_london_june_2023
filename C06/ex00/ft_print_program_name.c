/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:50:13 by tochen            #+#    #+#             */
/*   Updated: 2023/06/21 02:50:16 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++ ;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	ft_putstr(argv[0]);
	ft_putstr("\n");
	return (0);
}
