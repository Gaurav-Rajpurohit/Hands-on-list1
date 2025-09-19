/*
============================================================================
Name : 14.c
Author : Gaurav Rajpurohit
Description : 14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 22th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	struct stat st;

	lstat(argv[1], &st);

	if(S_ISREG(st.st_mode)){
		printf("%s  is a regular file\n", argv[1]);
	}
	else if(S_ISDIR(st.st_mode)){
		printf("%s is a directory\n", argv[1]);
	}
	else if(S_ISLNK(st.st_mode)){
		printf("%s  is a symbolic link\n", argv[1]);
	}
	else if(S_ISCHR(st.st_mode)){
		printf("%s  is a character device\n", argv[1]);
	}
	else if(S_ISBLK(st.st_mode)){
		printf("%s  is a block device\n", argv[1]);
	}
	else if(S_ISFIFO(st.st_mode)){
		printf("%s  is a FIFO (named pipe)\n", argv[1]);
	}
	else if(S_ISSOCK(st.st_mode)){
		printf("%s  is a socket.\n",argv[1]);
	}
	else{
		printf("%s is a of unknown type\n", argv[1]);
	}
	return 0;
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que14$ ./a.out file1.txt
file1.txt  is a regular file
*/