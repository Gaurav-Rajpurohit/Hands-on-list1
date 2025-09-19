/*
============================================================================
Name : 11b.c
Author : Gaurav Rajpurohit
Description :11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a.use dup2
Date: 18th Aug, 2025.
============================================================================
*/


#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1 = open("file2.txt",O_CREAT | O_RDWR | O_APPEND, 0644);
	int fd2 = dup2(fd1, 10);

	write(fd1, "Hello\n", 6);
	write(fd2, "Eren\n",5);

	close(fd1);
	close(fd2);
	return 0;
}

/*
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que11$ more file2.txt
Hello
Eren
*/
