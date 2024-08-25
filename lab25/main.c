#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pids[3];

    for (int i = 0; i < 3; i++) {
        pids[i] = fork();

        if (pids[i] < 0) {
            perror("fork");
            exit(1);
        } else if (pids[i] == 0) {
            printf("Child %d with PID %d\n", i + 1, getpid());
	    sleep(2);
            exit(0);
        }
    }

    int status;
    pid_t target_pid = pids[1];

    printf("Waiting for child with PID %d\n", target_pid);
    pid_t waited_pid = waitpid(target_pid, &status, 0);

    if (waited_pid == -1) {
        perror("Error while waitpid");
        exit(1);
    } else
    {
        printf("Child with PID %d exited with status %d\n", waited_pid, WEXITSTATUS(status));
    }

    return 0;
}

