#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void print_file_mode(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    int access_mode = flags & O_ACCMODE;
    switch (access_mode) {
        case O_RDONLY:
            printf("File is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode.\n");
            break;
        default:
            printf("Unknown file opening mode.\n");
            break;
    }

    if (flags & O_APPEND) {
        printf("File is opened in append mode.\n");
    }
    if (flags & O_NONBLOCK) {
        printf("File is opened in non-blocking mode.\n");
    }
    if (flags & O_SYNC) {
        printf("File is opened in synchronous I/O mode.\n");
    }
    if (flags & O_CREAT) {
        printf("File is opened with O_CREAT flag.\n");
    }
    if (flags & O_TRUNC) {
        printf("File is opened with O_TRUNC flag.\n");
    }
    if (flags & O_EXCL) {
        printf("File is opened with O_EXCL flag.\n");
    }
}

int main() {
    const char *filename = "test_file.txt";

    int fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    print_file_mode(fd);

    close(fd);

    return 0;
}

