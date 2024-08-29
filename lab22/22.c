/*
====================================================================================================================================================================================
Name : 22.c
Author : Rohan Sonawane
Description :
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("File is not opened");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Coudn't create file");
        return 1;
    }

    if (pid == 0) {
        char msg[] = "Writing to the file from the Child process.\n";
        write(fd, msg, sizeof(msg));
    } else {
        char msg[] = "Writing from the Parent process.\n";
        write(fd, msg, sizeof(msg));
    }
    close(fd);

    return 0;
}

/*
output:
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab22$ gcc 22.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab22$ ./a.out
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab22$ cat output.txt
Writing from the Parent process.
Writing to the file from the Child process.
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab22$ 
*/

