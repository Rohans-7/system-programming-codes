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

