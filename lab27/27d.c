/*
====================================================================================================================================================================================
Name : 27d.c
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
    char *args[] = {"ls", "-Rl", NULL};
    
    execv("/bin/ls", args);

    perror("execv failed");
    return 1;
}
/*
ohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ gcc 27d.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ ./a.out
.:
total 308
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    833 Aug 30 00:09  27a.c
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    648 Aug 30 00:12  27b.c
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    763 Aug 30 00:13  27c.c
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    180 Aug 30 00:14  27d.c
-rwxrwxr-x 1 rohan-sonawane rohan-sonawane  16056 Aug 30 00:14  a.out
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane 282119 Aug 25 23:00 'Pasted image.png'
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ 


*/

