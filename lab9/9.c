/*
============================================================================
Name : 9.c
Author : Rohan Sonawane
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 11th Aug, 2024.
============================================================================
*/
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

/*
Input:/a.out test.txt
Output:
a. Inode: 5767635
b. Number of hard links: 1
c. UID: 1000
d. GID: 1000
e. size:24 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Time of last access: Tue Aug 13 11:03:28 2024

i. Time of last modification: Sun Aug 11 16:15:57 2024

j. Time of last change: Sun Aug 11 16:15:57 2024


*/

