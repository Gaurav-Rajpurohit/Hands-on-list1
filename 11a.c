/*
============================================================================
Name : 11a.c
Author : Gaurav Rajpurohit
Description :11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a.use dup
Date: 18th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd1 = open("file1.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	int fd2 = dup(fd1);

	write(fd1, "Hello\n",6);
	write(fd2,"Gaurav\n",7);

	close(fd1);
	close(fd2);

	return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que11$ more file1.txt
Hello
Gaurav
*/