#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FILENAME "records.txt"
#define RECORD_SIZE 50

void write_lock(int fd, int record_number) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Write lock failed");
        exit(1);
    }
}

void read_lock(int fd, int record_number) {
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Read lock failed");
        exit(1);
    }
}

void unlock(int fd, int record_number) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_number * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Unlock failed");
        exit(1);
    }
}

void read_record(int fd, int record_number, char *buffer) {
    read_lock(fd, record_number);
    
    lseek(fd, record_number * RECORD_SIZE, SEEK_SET);
    read(fd, buffer, RECORD_SIZE);
    printf("Read Record %d: %s\n", record_number + 1, buffer);

    unlock(fd, record_number);
}

void write_record(int fd, int record_number, const char *data) {
    write_lock(fd, record_number);
    
    lseek(fd, record_number * RECORD_SIZE, SEEK_SET);
    write(fd, data, strlen(data));
    printf("Wrote Record %d: %s\n", record_number + 1, data);

    unlock(fd, record_number);
}

int main() {
    int fd = open(FILENAME, O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    char buffer[RECORD_SIZE] = {0};

    read_record(fd, 0, buffer);

    write_record(fd, 1, "Updated Record 2\n");

    read_record(fd, 1, buffer);

    close(fd);
    return 0;
}

