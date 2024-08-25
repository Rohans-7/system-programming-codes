#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
   // printf("Output using execl system call.\n");
   // if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) {
       // perror("execl failed");
     //   exit(1);
   // }
    
   // printf("Output using execlp system call.\n");
   // if (execlp("ls", "ls", "-Rl", NULL) == -1) {
     //   perror("execlp failed");
       // exit(1);
    //}

   // printf("Output using excle system call.\n");
   // char *envp[] = {NULL};

   // if (execle("/bin/ls", "ls", "-Rl", NULL, envp) == -1) {
    //    perror("execle failed");
      //  exit(1);
   // }

    //printf("Output using execv system call.\n");

   // char *args1[] = {"ls", "-Rl", NULL};

   // if (execv("/bin/ls", args1) == -1) {
     //   perror("execv failed");
       // exit(1);
   // }

   // printf("Output using execvp system call.\n");
   char *args2[] = {"ls", "-Rl", NULL};

    if (execvp("ls", args2) == -1) {
        perror("execvp failed");
        exit(1);
    }


    return 0;
}

