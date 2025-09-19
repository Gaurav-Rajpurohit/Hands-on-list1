/*
============================================================================
Name : 12.c
Author : Gaurav Rajpurohit
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
Date: 19th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd, flags;
	fd = open("file.txt", O_CREAT | O_RDWR, 0644);
	flags = fcntl(fd, F_GETFL);

	

	int mode = flags & O_ACCMODE;
	if(mode == O_RDONLY) printf("read only mode\n");
	else if(mode == O_RDWR) printf("read and write both mode\n");
	else printf("write mode only\n");

	close(fd);
	return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que12$ ./a.out
read and write both mode
*/