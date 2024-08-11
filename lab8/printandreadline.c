#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd=open("test.txt",O_RDONLY);

	if(fd==-1){
		perror("open");
		exit(1);
	}
	char c;

	while(read(fd,&c,1)>0){
		putchar(c);
	}

	close(fd);

	
	return 0;
}
