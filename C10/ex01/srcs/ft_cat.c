/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:01:45 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 13:01:50 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

#define BUF_SIZE 1024

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void    ft_puterror(char *str)
{
    while (*str)
        write(2, str++, 1);
}

void    display_file(char *program_name, char *file_name)
{
    int     fd;
    ssize_t read_size;
    char    buffer[BUF_SIZE + 1];

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr(basename(program_name));
        ft_putstr(": ");
        ft_putstr(file_name);
        ft_putstr(": ");
        ft_puterror(strerror(errno));
        ft_putstr("\n");
        return;
    }

    while ((read_size = read(fd, buffer, BUF_SIZE)) > 0)
    {
        buffer[read_size] = '\0';
        ft_putstr(buffer);
    }

    if (read_size < 0)
    {
        ft_putstr(basename(program_name));
        ft_putstr(": ");
        ft_putstr(file_name);
        ft_putstr(": ");
        ft_puterror(strerror(errno));
        ft_putstr("\n");
    }

    close(fd);
}

int     main(int argc, char **argv)
{
    int i;

    if (argc < 2)
    {
        ft_putstr("Please provide one or more files to read.\n");
        return (1);
    }

    i = 1;
    while (i < argc)
    {
        display_file(argv[0], argv[i]);
        i++;
    }

    return (0);
}
