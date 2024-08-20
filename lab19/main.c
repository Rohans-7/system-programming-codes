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

