/*
============================================================================
Name : 16a.c
Author : Gaurav Rajpurohit
Description : Write a program to perform mandatory locking.
a.Implement write Lock
Date: 16th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	int fd;
	struct flock lock;

	fd = open("file1.txt", O_RDWR);

	lock.l_type = F_WRLCK; // write lock 
	lock .l_whence = SEEK_SET;
	lock. l_start - 0;
	lock. l_len = 0;
	
	printf("Trying for write lock\n");
	fcntl(fd, F_SETLKW, &lock);
	
	printf("Write lock is there press Enter key to release... otherwise keep remain silent!!\n");

	getchar();

	lock.l_type = F_UNLCK;

	fcntl(fd, F_SETLK, &lock);

	printf("Write lock relased Enjoy and chill!!\n");

	close(fd);

	return 0;
}

/*
OUTPUT
On one terminal 

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que16$ ./a.out
Trying for write lock
Write lock is there press Enter key to release... otherwise keep remain silent!!


On other terminal

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que16$ ./a.out
Trying for write lock


*/
