/*
============================================================================================================================================================
Name : 26.c
Author : Gaurav Rajpurohit
Description: Write a program to execute an executable program. Pass input arguments if needed (example: ./a.out name).
Date: Sept 6th, 2025.
============================================================================================================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]){
	printf("trying execl to execute another program\n");
	execl("./subtraction","subtraction",argv[1],argv[2],NULL);
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que26$ cc subtraction.c -o subtraction
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que26$ cc 26.c -o 26
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que26$ ./26 4 3
trying execl to execute another program
3 - 4 = -1
*/