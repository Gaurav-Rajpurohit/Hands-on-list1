/*
============================================================================
Name : 21.c
Author : Gaurav Rajpurohit
Description : Write a program, call fork and print the parent and child process id.
Date: 29th Aug, 2025.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	if(!fork()){
		printf("My process id : %d and Parent process id : %d\n",getpid(), getppid());
	}
	else{
		printf("Parent's process id:%d\n", getpid());
	}
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que21$ ./a.out
Parent's process id:4888
My process id : 4889 and Parent process id : 4888

*/