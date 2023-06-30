/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:47:30 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 09:47:32 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char buffer[101];
	int fd;
	int bytes_read;

	if (argc == 1)
	{
		write(1, "File name missing.\n", 20);
		return(1);
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 21);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 19);
		return (1);
	}
	bytes_read = 100;
	while (bytes_read == 100)
	{
		bytes_read = read(fd, buffer, 100);
		if (bytes_read == -1)
		{
			write(1, "Cannot read file.\n", 19);
			close(fd);
			return (1);
		}
		if (write(1, buffer, bytes_read) == -1)
		{
			close(fd);
			return (1);
		}
	}
	if (close(fd) == -1)
	{
		return (1);
	}
	return (0);
}
