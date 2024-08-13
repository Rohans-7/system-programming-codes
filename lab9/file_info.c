#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>

void fileInformation(const char *file_path){
	struct stat file_stat;

	if(stat(file_path,&file_stat)==-1){
		perror("stat");
		return;
	}

	printf("a. Inode: %lu\n",file_stat.st_ino);
	printf("b. Number of hard links: %lu\n",file_stat.st_nlink);
	printf("c. UID: %u\n",file_stat.st_uid);
	printf("d. GID: %u\n",file_stat.st_gid);
	printf("e. size:%ld bytes\n",file_stat.st_size);
	printf("f. Block size: %ld bytes\n",file_stat.st_blksize);
	printf("g. Number of blocks: %ld\n",file_stat.st_blocks);
	printf("h. Time of last access: %s\n",ctime(&file_stat.st_atime));
	printf("i. Time of last modification: %s\n",ctime(&file_stat.st_mtime));	printf("j. Time of last change: %s\n",ctime(&file_stat.st_ctime));
}


int main(int argc,char *argv[]){
	if(argc!=2){
		fprintf(stderr,"Usage: %s<file_path>\n",argv[0]);
		return 1;
	}

	fileInformation(argv[1]);

	return 0;
}
