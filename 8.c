/*
============================================================================
Name : 8.c
Author : Gaurav Rajpurohit
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 16th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd1 = open("file1.txt" , O_RDONLY);

	char buff[1000];
	int i = 0;
	char ch;

	while(read(fd1, &ch, 1)> 0){
		if(ch == '\n'){
			buff[i] = '\0';
			printf("%s\n",buff);
			i =0;
		}
		else{
			buff[i] = ch;
			i++;
		}
	}
	if(i > 0){
		buff[i]= '\0';
		printf("%s\n", buff);
	}
	close(fd1);
	return 0;
}
/*
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que8$ more file1.txt
hello world
hi how are you

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que8$ ./a.out
hello world
hi how are you
*/