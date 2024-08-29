/*
====================================================================================================================================================================================
Name : 28.c
Author : Rohan Sonawane
Description :
Write a program to get maximum and minimum real time priority.

Date : 28th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main() {
    int mxpriority, mnpriority;

    mxpriority = sched_get_priority_max(SCHED_FIFO);
    if (mxpriority == -1) {
        perror("Failed to get priority");
        exit(1);
    }

    mnpriority = sched_get_priority_min(SCHED_FIFO);
    if (mnpriority == -1) {
        perror("Failed to get priority");
        exit(1);
    }

    printf("Max. priority: %d\n", mxpriority);
    printf("Min. priority: %d\n", mnpriority);

    return 0;
}
/*
output:
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab28$ gcc 28.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab28$ ./a.out
Max. priority: 99
Min. priority: 1
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab28$ 



*/
