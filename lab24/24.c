/*
====================================================================================================================================================================================
Name : 24.c
Author : Rohan Sonawane
Description :Write a program to create an orphan process.

Date : 28th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        sleep(1);  // Give the parent time to terminate
        printf("Child process (PID: %d) initial Parent PID: %d\n", getpid(), getppid());

        sleep(10);  // Ensure enough time for reparenting to init (PID 1)
        printf("Child process (PID: %d) after reparenting, Parent PID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process (PID: %d) is terminating.\n", getpid());
        exit(0);  // Parent process terminates, leaving the child process orphaned
    }

    return 0;
}

/*
Output:
24$ ./a.out &
[1] 16099
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab24$ Parent process (PID: 16099) is terminating.
Child process (PID: 16100) initial Parent PID: 1533
Child process (PID: 16100) after reparenting, Parent PID: 1533

rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab24$ ps -o ppid= -p 1533
      1
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab24$ 

*/

