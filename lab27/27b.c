#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-Rl", (char *)NULL);
    perror("execlp failed");
    return 1;
}

/*

$ gcc 27b.c
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ ./a.out
.:
total 300
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    833 Aug 30 00:09  27a.c
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane    144 Aug 30 00:11  27b.c
-rwxrwxr-x 1 rohan-sonawane rohan-sonawane  16000 Aug 30 00:12  a.out
-rw-rw-r-- 1 rohan-sonawane rohan-sonawane 282119 Aug 25 23:00 'Pasted image.png'
rohan-sonawane@rohan-sonawane-HP-Pavilion-Laptop-14-ce3xxx:~/SS hands on lab/lab27$ 


*/

