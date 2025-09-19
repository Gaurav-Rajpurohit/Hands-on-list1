/*
============================================================================
Name : 7.c
Author : Gaurav Rajpurohit
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 16th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1 = open("file1.txt", O_RDWR,0644);
	char buf[100];
	int fd2 = open("file2.txt", O_RDWR | O_CREAT |O_TRUNC , 0644);
	int n;

	while((n= read(fd1,buf,sizeof(buf))) > 0){
		write(fd2, buf, n);
	}
	close(fd1);
	close(fd2);
}
/*OUTPUT

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que7$ more file1.txt
hii gaurav
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que7$ more file2.txt
hii gaurav
*/