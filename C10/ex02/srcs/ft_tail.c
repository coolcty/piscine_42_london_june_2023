/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:42:29 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 13:42:32 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 4096  // You can adjust the buffer size as needed

void ft_tail(char *file, int N) {
    char *buffer = (char *)malloc(BUFF_SIZE * sizeof(char));
    int fd = open(file, O_RDONLY);

    if (fd < 0) {
        write(2, "Cannot open file.\n", 18);
        free(buffer);
        return;
    }

    int buffer_index = 0;
    int total_bytes_read = 0;
    int bytes_read;
    while ((bytes_read = read(fd, &buffer[buffer_index], 1)) > 0) {
        buffer_index = (buffer_index + 1) % N;
        total_bytes_read += bytes_read;
    }

    if (bytes_read < 0) {
        write(2, "Cannot read file.\n", 18);
        free(buffer);
        return;
    }

    int bytes_to_write = (total_bytes_read < N) ? total_bytes_read : N;
    for (int i = 0; i < bytes_to_write; ++i) {
        write(STDOUT_FILENO, &buffer[(buffer_index + i) % N], 1);
    }

    free(buffer);
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc == 3 && strncmp(argv[1], "-c", 2) == 0) {
        int N = atoi(argv[1] + 2);
        if (N > 0) {
            ft_tail(argv[2], N);
        } else {
            write(2, "Invalid count.\n", 15);
        }
    } else {
        write(2, "Usage: ft_tail -cN <file>\n", 24);
    }
    return 0;
}
