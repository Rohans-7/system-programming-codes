#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void apply_mandatory_read_lock(int fd) {
    struct flock lock;

    lock.l_type = F_RDLCK;  
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;        
    lock.l_len = 0;         

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error applying mandatory read lock");
        exit(EXIT_FAILURE);
    } else {
        printf("Mandatory read lock applied.\n");
    }
}

void release_lock(int fd) {
    struct flock lock;

    lock.l_type = F_UNLCK;   
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;        
    lock.l_len = 0;         

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error releasing lock");
        exit(EXIT_FAILURE);
    } else {
        printf("Lock released.\n");
    }
}

int main() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    apply_mandatory_read_lock(fd);

    printf("Press Enter to release the lock and exit...\n");
    getchar();

    release_lock(fd);

    close(fd);

    return 0;
}

