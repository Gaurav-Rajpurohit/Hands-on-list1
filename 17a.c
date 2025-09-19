
/*
============================================================================
Name : 17a.c
Author : Gaurav Rajpurohit
Description : Write a program to open a file, store a ticket number and exit.
Date: Sept 6th, 2025.
============================================================================
*/


#include <stdio.h>       
#include <unistd.h>      
#include <fcntl.h> 

int main(){
	int fd;
	struct {
		int ticket_no;
	} db;

	db.ticket_no = 0;
	fd = open("db",O_CREAT|O_RDWR,0744);
	write(fd,&db,sizeof(db));
	close(fd);
	
	fd = open("db",O_RDONLY);
	read(fd,&db,sizeof(db));
	printf("Ticket no: %d\n",db.ticket_no);
	close(fd);
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que17$ cc 17a.c -o tinfo
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que17$ ./tinfo
Ticket no: 0
*/