/*
============================================================================
Name : 1a.c
Author : Gaurav Rajpurohit
Description :Create the following types of a files using (i) shell command (ii) system call
	a.soft link (symlink system call)
Date: 9th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	symlink("file1.txt","file1_soft");
		
	
	printf("Soft LInK Created SUccessfully\n");
}

/*
OUTPUT
lrwxrwxrwx 1 gaurav176 gaurav176     9 Aug 14 14:32 file1_soft -> file1.txt
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que1$ ./a.out
Soft LInK Created SUccessfully


*/
