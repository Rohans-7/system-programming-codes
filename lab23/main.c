#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Child not created");
        return 1;
    }

    if (pid == 0) {
        printf("Child process is terminating.\n");
        exit(0);
    } else {
        printf("Parent process creating child process.\n");
        printf("Parent process is sleeping for 10 seconds...\n");
        sleep(10);

        printf("Parent process is now calling wait().\n");
        wait(NULL);

        printf("Now parent process reaped the Zombie process\n");
    }

    return 0;
}

