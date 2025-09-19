/*
============================================================================
Name : 23.c
Author : Gaurav Rajpurohit
Description : Write a program to create a Zombie state of the running program.
Date: 29th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(){

	if(!fork()){
		printf("child process:%d and ppid : %d \n", getpid(),getppid());
	}
	else{
		 sleep(223);
	}
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que23$ ./a.out &
[1] 4997

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que23$ child process:4998 and ppid : 4997 

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que23$ top -p 4997


    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND                                                                                                          
   4997 gaurav1+  20   0    2548   1304   1304 S   0.0   0.0   0:00.00 a.out                                                                                                            


*/