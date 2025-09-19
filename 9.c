/*
============================================================================
Name : 9.c
Author : Gaurav Rajpurohit
Description :9. Write a program to print the following information about a given file.
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
Date: 16th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<time.h>

int main(){
	struct stat st;

	if(stat("file1.txt", &st) == -1){
		perror("Error in the stat portion" );
		return 1;
	}

	printf("a.inode: %lu \n", (unsigned long) st.st_ino);
	printf("b. hardlinks : %lu \n", (unsigned long) st. st_nlink);
	printf("c.uid :%u\n", st.st_uid);
	printf("d. gid: %u \n", st.st_gid);
	printf("e. size: %lld bytes \n",(long long) st. st_size);
	printf("f. block size: %lld \n", (long long) st.st_blksize);
	printf("g. bolcks: % lld \n", (long long) st.st_blocks);
	printf("h. last access: %s", ctime(&st.st_atime));
	printf("i. last modification: %s", ctime(&st.st_mtime));
	printf("j. last change: %s",ctime(&st.st_ctime));

return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que9$ ./a.out
a.inode: 1972348 
b. hardlinks : 1 
c.uid :1000
d. gid: 1000 
e. size: 12 bytes 
f. block size: 4096 
g. bolcks:  8 
h. last access: Sun Aug 17 23:14:38 2025
i. last modification: Sat Aug 16 01:44:42 2025
j. last change: Sat Aug 16 01:44:42 2025
*/