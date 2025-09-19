/*
============================================================================
Name : 17b.c
Author : Gaurav Rajpurohit
Description :Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: Sept 6th, 2025.
============================================================================
*/


#include <stdio.h>       
#include <unistd.h>     
#include <fcntl.h> 

int main(){
	struct {
		int ticket_no;
	} db;

	struct flock lock;
	int fd;
	fd = open("db",O_RDWR);

	printf("before entering into cretical section");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section\n");

	read(fd,&db,sizeof(db));
	printf("Current ticket number: %d\n", db.ticket_no);
	db.ticket_no++;
	
	lseek(fd,0,SEEK_SET);
	write(fd,&db,sizeof(db));
	
	printf("Press enter to unlock\n");
	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Exited critical section\n");	
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que17$ ./tinc
before entering into cretical sectionInside the critical section
Current ticket number: 1
Press enter to unlock

Exited critical section
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que17$ ./tinc
before entering into cretical sectionInside the critical section
Current ticket number: 3
Press enter to unlock

Exited critical section

*/