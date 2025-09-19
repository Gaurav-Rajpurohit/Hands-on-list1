/*
============================================================================
Name : 13.c
Author : Gaurav Rajpurohit
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 19th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	fd_set rfds;

	struct timeval tv;
	int retval;


	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	tv.tv_sec = 10;
	tv.tv_usec = 0;
	
	printf("Waiting for input for 10 seconds... \n");
	retval = select(1, &rfds, NULL, NULL, &tv);

	if(retval){
		printf("Data is available now\n");
	}
	else{
		printf("NO data available within 10 seconds so I am OUT!!\n");
	}
	return 0;
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que13$ ./a.out
Waiting for input for 10 seconds... 
ls
Data is available now
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que13$ ls
13.c  a.out
*/