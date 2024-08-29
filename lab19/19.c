/*
====================================================================================================================================================================================
Name : 19.c
Author : Rohan Sonawane
Description :
Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

static inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    pid_t pid;

    start = rdtsc();

    pid = getpid();

    end = rdtsc();

    printf("Time taken by getpid(): %llu CPU cycles\n", end - start);

    return 0;
}

/*

output:
ohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab19$ ./a.out
Time taken by getpid(): 5442 CPU cycles
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab19$ 

*/



