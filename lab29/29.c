/*
====================================================================================================================================================================================
Name : 29.c
Author : Rohan Sonawane
Description :
Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

void printPolicy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current Scheduling Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current Scheduling Policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current Scheduling Policy: SCHED_OTHER (Default)\n");
            break;
        default:
            printf("Unknown Scheduling Policy\n");
    }
}

int main(int argc, char *argv[]) {
    int pid;
    int policy;
    struct sched_param param;

    pid = getpid();

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(1);
    }

    printPolicy(policy);

    param.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        exit(1);
    }

    printf("Scheduling policy changed to SCHED_FIFO.\n");

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(1);
    }

    printPolicy(policy);

    param.sched_priority = sched_get_priority_max(SCHED_RR);
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
        exit(1);
    }

    printf("Scheduling policy changed to SCHED_RR.\n");

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(1);
    }

    printPolicy(policy);

    return 0;
}

/*
output:
9$ ./a.out fifo
Current Scheduling Policy: SCHED_OTHER (Default)
sched_setscheduler: Operation not permitted
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab29$ sudo ./a.out fifo
[sudo] password for rohan-sonawane: 
Current Scheduling Policy: SCHED_OTHER (Default)
Scheduling policy changed to SCHED_FIFO.
Current Scheduling Policy: SCHED_FIFO
Scheduling policy changed to SCHED_RR.
Current Scheduling Policy: SCHED_RR
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab29$ 


*/

