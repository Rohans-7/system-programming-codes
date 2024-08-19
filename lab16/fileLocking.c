#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void lock_file(int fd, int lock_type) {
    struct flock lock;
    lock.l_type = lock_type; // F_WRLCK for write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // Lock the whole file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error locking file");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    lock_file(fd, F_WRLCK);

    printf("Write lock is applied. Press Enter to release lock...\n");
    getchar();

    lock_file(fd, F_UNLCK);
    printf("Write lock released.\n");

    close(fd);
    return 0;
}

