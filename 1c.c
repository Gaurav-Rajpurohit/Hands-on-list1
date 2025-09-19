/*
============================================================================
Name : 1c.c
Author : Gaurav Rajpurohit
Description :Create the following types of a files using (i) shell command (ii) system call
	c. FIFO (mkfifo Library Function or mknod system call)
Date: 17th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
	mkfifo("myfifo",0666);
	return 0;
}
/*
OUTPUT
prw-rw-r-- 1 gaurav176 gaurav176     0 Aug 17 15:02 myfifo

*/