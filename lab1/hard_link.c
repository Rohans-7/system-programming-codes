#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(){
	const char *oldPath="/home/rohan-sonawane/SS hands on lab/lab 1/test1.txt";
	const char *newPath="/home/rohan-sonawane/SS hands on lab/lab 1/hardlink/test2.txt";

	int res=link(oldPath,newPath);
	if(res==0){
		printf("Hard link created successfully.\n");
	}
	else{
		perror("link");
	}
	return 0;
}
