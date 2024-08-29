/*
============================================================================
Name : 11.c
Author : Rohan Sonawane
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 11th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILENAME "test_file.txt"
#define BUFFER_SIZE 256

void check_file_content() {
    char buffer[BUFFER_SIZE];
    int fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_read;
    printf("File content:\n");
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(fd);
}

int main() {
    int fd_original, fd_dup, fd_dup2, fd_fcntl;
    const char *text1 = "Text written by original descriptor.\n";
    const char *text2 = "Text written by dup descriptor.\n";
    const char *text3 = "Text written by dup2 descriptor.\n";
    const char *text4 = "Text written by fcntl descriptor.\n";

    fd_original = open(FILENAME, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd_original == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fd_dup = dup(fd_original);
    if (fd_dup == -1) {
        perror("Failed to duplicate file descriptor using dup");
        close(fd_original);
        exit(EXIT_FAILURE);
    }

    fd_dup2 = dup2(fd_original, fd_dup + 1);
    if (fd_dup2 == -1) {
        perror("Failed to duplicate file descriptor using dup2");
        close(fd_original);
        close(fd_dup);
        exit(EXIT_FAILURE);
    }

    fd_fcntl = fcntl(fd_original, F_DUPFD, fd_dup2 + 1);
    if (fd_fcntl == -1) {
        perror("Failed to duplicate file descriptor using fcntl");
        close(fd_original);
        close(fd_dup);
        close(fd_dup2);
        exit(EXIT_FAILURE);    
    }
	
    if (write(fd_original, text1, strlen(text1)) == -1) {
        perror("Failed to write using original descriptor");
    }

    if (write(fd_dup, text2, strlen(text2)) == -1) {
        perror("Failed to write using dup descriptor");
    }

    if (write(fd_dup2, text3, strlen(text3)) == -1) {
        perror("Failed to write using dup2 descriptor");
    }

    if (write(fd_fcntl, text4, strlen(text4)) == -1) {
        perror("Failed to write using fcntl descriptor");
    }

    close(fd_original);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    check_file_content();

    return 0;
}

/*
Output: 
File content:
Text written by original descriptor.
Text written by dup descriptor.
Text written by dup2 descriptor.
Text written by fcntl descriptor.
Text written by original descriptor.
Text written by dup descriptor.
Text written by dup2 descriptor.
Text written by fcntl descriptor.
*/

