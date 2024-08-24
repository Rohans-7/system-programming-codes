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

