/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochen <tochen@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:58:13 by tochen            #+#    #+#             */
/*   Updated: 2023/06/29 13:58:15 by tochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex(int ch) {
    const char *hex_digits = "0123456789abcdef";
    write(STDOUT_FILENO, &hex_digits[ch / 16], 1);
    write(STDOUT_FILENO, &hex_digits[ch % 16], 1);
}

void print_ascii(unsigned char *buffer, int size) {
    int i;
    write(STDOUT_FILENO, " |", 2);
    for (i = 0; i < size; i++) {
        if (buffer[i] >= ' ' && buffer[i] <= '~') {
            write(STDOUT_FILENO, &buffer[i], 1);
        } else {
            write(STDOUT_FILENO, ".", 1);
        }
    }
    write(STDOUT_FILENO, "|\n", 2);
}

void print_offset(long offset) {
    char hex_offset[9];
    sprintf(hex_offset, "%08lx", offset);
    write(STDOUT_FILENO, hex_offset, 8);
    write(STDOUT_FILENO, "  ", 2);
}

void ft_hexdump(char *file) {
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        write(2, "Cannot open file.\n", 18);
        return;
    }

    unsigned char buffer[16];
    int bytes_read;
    int i = 0;
    long offset = 0;

    while ((bytes_read = read(fd, &buffer[i], 1)) > 0) {
        if (i % 16 == 0) {
            print_offset(offset);
        }
        print_hex(buffer[i]);
        write(STDOUT_FILENO, " ", 1);
        if (i % 16 == 7) {  // add extra space in the middle
            write(STDOUT_FILENO, " ", 1);
        }
        i++;
        offset++;

        if (i % 16 == 0) {
            print_ascii(buffer, i);
            i = 0;
        }
    }

    if (i != 0) {  // for the last line
        for (int j=i; j < 16; j++) {
            write(STDOUT_FILENO, "   ", 3);  // to align the ASCII part
            if (j % 16 == 7) {  // add extra space in the middle
                write(STDOUT_FILENO, "  ", 1);
            }
        }
        print_ascii(buffer, i);
		
    }

    if (bytes_read < 0) {
        write(2, "Cannot read file.\n", 18);
    }
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc == 3 && strncmp(argv[1], "-C", 2) == 0) {
        ft_hexdump(argv[2]);
    } else {
        write(2, "Usage: ft_hexdump -C <file>\n", 27);
    }
    return 0;
}
