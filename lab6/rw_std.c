#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	char message[20];
	read(STDOUT_FILENO,message,20);
	write(STDIN_FILENO,message,20);

	return 0;
}
