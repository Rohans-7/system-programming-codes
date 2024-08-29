/*
====================================================================================================================================================================================
Name : 27c.c
Author : Rohan Sonawane
Description :Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    extern char **environ;
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, environ);
    
    perror("execle failed");
    return 1;
}

/*
27$ gcc 27c.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ ./a.out
.:
total 304
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    833 Aug 30 00:09  27a.c
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    648 Aug 30 00:12  27b.c
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    190 Aug 30 00:13  27c.c
-rwxrwxr-x 1 rohan-sonawane rohan-sonawane  16072 Aug 30 00:13  a.out
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane 282119 Aug 25 23:00 'Pasted image.png'
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ 

*/
