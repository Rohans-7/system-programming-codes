/*
====================================================================================================================================================================================
Name : 20.c
Author : Rohan Sonawane
Description :
Find out the priority of your running program. Modify the priority with nice command

Date : 28th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int priority;
    pid_t pid;

    pid = getpid();
    priority = getpriority(PRIO_PROCESS, pid);
    printf("Current prio.: %d\n", priority);

    int nPriority = 5;
    int ans = nice(nPriority);

    if (ans == -1) {
        perror("Can't set the priority");
    } else {
        priority = getpriority(PRIO_PROCESS, pid);
        printf("New prio. of the process: %d\n", priority);
    }

    return 0;
}

/*
output:
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab20$ gcc 20.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab20$ ./a.out
Current prio.: 0
New prio. of the process: 5
*/
