
/*
============================================================================
Name : 19.c
Author : Gaurav Rajpurohit
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 29th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__ ("rdtsc":"=A"(dst));
}

int main(void){
	int i , nano;
	unsigned long long int start, end;
	start = rdtsc();
	for(i =0;i<=10;i++)
		getppid();
	end= rdtsc();
	nano = (end - start)/2.40;
	printf("The function takes %d nanosec \n",nano);
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que19$ ./a.out
The function takes 2890 nanosec 
*/