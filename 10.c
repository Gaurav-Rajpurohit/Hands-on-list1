/*
============================================================================
Name : 10.c
Author : Gaurav Rajpurohit
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 16th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd;
	char buf1[]= "WELCOMEBRO";
	char buf2[]= "HELLOBRUHH";

	fd = open("file1.txt",O_RDWR | O_CREAT | O_TRUNC, 0644);

	write(fd, buf1, 10);

	int pos = lseek(fd, 20, SEEK_CUR);
	printf("File pointer after lseek: %ld\n", (long)pos);
	
	write(fd, buf2, 10);

	close(fd);
	return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que10$ ./a.out
File pointer after lseek: 30

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que10$ od -c file1.txt
0000000   W   E   L   C   O   M   E   B   R   O  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0   H   E
0000040   L   L   O   B   R   U   H   H
0000050

*/