/*
============================================================================
Name : 25.c
Author : Gaurav Rajpurohit
Description :  Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 29th Aug, 2025.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int i, j, k;

	if(!(i= fork()))
		sleep(1);
	else if(!(j=fork()))
		sleep(3);
	else if(!(k= fork()))
		sleep(10);
	else
		waitpid(getpid(),NULL,0);
		perror("ret: ");
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que25$ ./a.out
ret: : No child processes
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que25$ ret: : Success
ret: : Success
ret: : Success


*/
