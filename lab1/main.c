#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(){
	const char *target="/home/rohan-sonawane/SS hands on lab/lab 1/test1.txt";
	const char *linkpath="/home/rohan-sonawane/SS hands on lab/lab 1/test3.txt";
	int res=symlink(target,linkpath);
	if(res==0){
		printf("Symbolic link created successfully.\n");
	}
	else{
		perror("symlink");
	}
	return 0;
}
