/*
============================================================================
Name : 6.c
Author : Gaurav Rajpurohit
Description :6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 16th Aug, 2025.
============================================================================
*/

#include<unistd.h>

int main() {
	char buff[100];
	int n;
	n = read(0, buff, sizeof(buff));
	write(1, buff, n);
	return 0;
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que6$ ./a.out
Hiii how are you brother
Hiii how are you brother
*/