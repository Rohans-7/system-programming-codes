/*
============================================================================
Name : 13.c
Author : Rohan Sonawane
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 11th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>

int main() {
    fd_set read_fds;
    struct timeval timeout;
    int ret;

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    ret = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("No data available within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            printf("Data is available within 10 seconds.\n");
        }
    }

    return 0;
}

/*
test.txt
Data is available within 10 seconds.
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab13$ test.txt
test.txt: command not found
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab13$ ./a.out
No data available within 10 seconds.
*/
