/*
============================================================================
Name : 4.c
Author : Gaurav Rajpurohit
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 17th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


int main(){
	int fd;
	fd = open("myfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
	close(fd);
	return 0;

}
/*
OUTPUT
total 24
-rw-rw-r-- 1 gaurav176 gaurav176   182 Aug 17 15:11 4.c
-rwxrwxr-x 1 gaurav176 gaurav176 16000 Sep  2 18:06 a.out
-rw-rw-r-- 1 gaurav176 gaurav176    12 Aug 15 20:39 myfile.txt
*/
