
/*
============================================================================
Name : 29.c
Author : Gaurav Rajpurohit
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 29th Aug, 2025.
============================================================================
*/

#include<sys/types.h>
#include<sched.h>
#include<stdio.h>
#include<unistd.h>

struct sched_param p;
int main(){
	p.sched_priority = 10;
	printf(" ret = %d\n",sched_setscheduler(0,SCHED_FIFO,&p));
	printf("\n The scheduling policy is = %d\n",sched_getscheduler(getpid()));
	printf(" ret = %d\n",sched_setscheduler(0,SCHED_RR,&p));
	printf("\n The scheduling policy is %d\n", sched_getscheduler(getpid()));
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que29$ ./a.out
 ret = -1

 The scheduling policy is = 0
 ret = -1

 The scheduling policy is 0
 */