#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	for(int i=1; i<=5; ++i){
		char filename[20];
		snprintf(filename,sizeof(filename),"file%d.txt",i);
		int fd=open(filename,O_CREAT,O_WRONLY,O_TRUNC,0644);
		if(fd<0){
			perror("open");
			return 1;
		}
		close(fd);
	}
	for(;;){
		sleep(1);
	}

	return 0;
}
