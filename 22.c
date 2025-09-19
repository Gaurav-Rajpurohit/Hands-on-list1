/*
============================================================================
Name : 22.c
Author : Gaurav Rajpurohit
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 29th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
	char buff1[250];
	char buff2[250];
	int fd = open("file1.txt",O_RDWR | O_CREAT, 0644);

	if(!fork()){
		sprintf(buff1, "child process  : pid = %d  ppid = %d ",getpid(),getppid());
	       write(fd,buff1,strlen(buff1));
      		close(fd);
 	}
	
	else{
		sprintf(buff2, "parent process  : pid = %d ",getpid());
               write(fd,buff2,strlen(buff2));
                close(fd);
	}
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que22$ more file1.txt
parent process  : pid = 4943 child process  : pid = 4944  ppid = 4943 

*/