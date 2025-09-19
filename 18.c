
/*
============================================================================
Name : 18.c
Author : Gaurav Rajpurohit
Description :  18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: sept 6th, 2025.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct train {
    int train_num;
    int ticket_count;
};

int main() {
    int fd;
    struct train db[3];
    fd = open("record.txt", O_RDWR | O_CREAT, 0644);
    

    if (read(fd, db, sizeof(db)) != sizeof(db)) {
        for (int i = 0; i < 3; i++) {
            db[i].train_num = i + 1;
            db[i].ticket_count = 0;
        }
        lseek(fd, 0, SEEK_SET);
        write(fd, db, sizeof(db));
    }

    int input;
    printf("Select train number: 1, 2, 3\n");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(struct train);
    lock.l_len = sizeof(struct train);
    lock.l_pid = getpid();

    lseek(fd, (input - 1) * sizeof(struct train), SEEK_SET);
    read(fd, &db[input - 1], sizeof(struct train));

    fcntl(fd, F_SETLKW, &lock);

    printf("Current ticket count: %d\n", db[input - 1].ticket_count);
    db[input - 1].ticket_count++;

    lseek(fd, (input - 1) * sizeof(struct train), SEEK_SET);
    write(fd, &db[input - 1], sizeof(struct train));

    getchar(); getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Ticket booked with number %d\n", db[input - 1].ticket_count);
    close(fd);
    return 0;
}
/*OUTPUT

on first terminal
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que18$ ./a.out
Select train number: 1, 2, 3
2
Current ticket count: 5

//on second terminal
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que18$ ./a.out
Select train number: 1, 2, 3
2
 
// first terminal
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que18$ ./a.out
Select train number: 1, 2, 3
2
Current ticket count: 5
2
Ticket booked with number 6

 
//on second terminal after completing the task at terminal 1
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que18$ ./a.out
Select train number: 1, 2, 3
2
Current ticket count: 6


*/