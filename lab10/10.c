/*
============================================================================
Name : 10.c
Author : Rohan Sonawane
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 11th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    int fd;
    ssize_t bytes_written;
    off_t offset;

    fd = open("text.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    bytes_written = write(fd, "I am Rohan S.", 10);
    if (bytes_written == -1) {
        perror("Error writing to the file");
        close(fd);
        return 1;
    }

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error seeking in the file");
        close(fd);
        return 1;
    } else {
        printf("Lseek returned offset: %ld\n", offset);
    }

    bytes_written = write(fd, "ABCDEFGHIJ", 10);
    if (bytes_written == -1) {
        perror("Error writing to the file");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}

/*
./a.out
Lseek returned offset: 20
Input: od -c test.txt
output:
0000000   T   h   i   s       i   s       t   h   e       t   e   m   p
0000020       f   i   l   e   .  \n
0000027
*/

