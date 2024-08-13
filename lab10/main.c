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

