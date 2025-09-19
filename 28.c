
/*
============================================================================
Name : 28.c
Author : Gaurav Rajpurohit
Description : 28. Write a program to get maximum and minimum real time priority.
Date: 29th Aug, 2025.
============================================================================
*/


#include<sys/types.h>
#include<sched.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	printf("The max real time priority(FIFO) = %d\n",sched_get_priority_max(SCHED_FIFO));
	printf("The min real time priority(FIFO) = %d\n",sched_get_priority_min(SCHED_FIFO));
	printf("The max real time priority(RR) = %d\n",sched_get_priority_max(SCHED_RR));
	printf("The min real time priority(RR) = %d\n",sched_get_priority_min(SCHED_RR));
	printf("The max real time priority = %d\n",sched_get_priority_max(SCHED_OTHER));
	printf("The min real time priorit) = %d\n",sched_get_priority_min(SCHED_OTHER));
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que28$ ./a.out
The max real time priority(FIFO) = 99
The min real time priority(FIFO) = 1
The max real time priority(RR) = 99
The min real time priority(RR) = 1
The max real time priority = 0
The min real time priorit) = 0
*/
