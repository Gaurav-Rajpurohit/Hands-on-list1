/*
============================================================================
Name : 20.c
Author : Gaurav Rajpurohit
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 29th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
	printf("The current program's prirority is %d\n", getpriority(PRIO_PROCESS,0));
	nice(6);
	printf("Updated program's priotity is %d\n", getpriority(PRIO_PROCESS,0));


}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que20$ ./a.out
The current program's prirority is 0
Updated program's priotity is 6
*/
