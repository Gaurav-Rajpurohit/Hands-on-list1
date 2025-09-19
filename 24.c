/*
============================================================================================================================================================
Name : 24.c
Author :	Gaurav Rajpurohit
Description: Write a program to create an orphan process.
Date: Sept 6, 2025.
============================================================================================================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	pid_t pid = fork();

	if(pid == 0){
		sleep(10);
		printf("child process area\n");
		printf("child process id :%d and parent's process id : %d\n",getpid(),getppid());
	}
	else{
		printf("parent process area \n");
		printf("parent process id :%d and child's process id: %d\n",getpid(),pid);
		exit(0);
	}
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que24$ ./a.out
parent process area 
parent process id :7469 and child's process id: 7470
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que24$ child process area
child process id :7470 and parent's process id : 2033
*/