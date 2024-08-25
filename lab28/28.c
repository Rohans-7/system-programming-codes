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

