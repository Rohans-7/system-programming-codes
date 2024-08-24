#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(){
	printf("The parent process pid is :%d\n",getpid());
	int f=fork();
	if(f==0){
		printf("We're in the child process wit pid:%d\n",getpid());
	}
	else if(f>0){
		printf("W're in the parent process with Child pid: %d and parent pid :%d\n",f,getppid());
	}
	else{
		printf("We're in the parent process but child was not created\n");
	}
	return 0;
}
