/*
============================================================================
Name : 11c.c
Author : Gaurav Rajpurohit
Description :11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a.use fcntl
Date: 18th Aug, 2025.
============================================================================
*/

#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd = open("file3.txt",O_CREAT | O_RDWR | O_APPEND, 0644);
	int fd2 = fcntl(fd, F_DUPFD, 0);

	write(fd, "1374\n",5);
	write(fd2, "5156\n", 5);

	close(fd);
	close(fd2);
	return 0;
}


/*
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que11$ more file3.txt
1374
5156
*/
