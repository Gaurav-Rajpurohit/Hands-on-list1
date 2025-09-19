/*
============================================================================
Name : 16b.c
Author : Gaurav Rajpurohit
Description : Write a program to perform mandatory locking.
a.Implement read Lock
Date: 16th Aug, 2025.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
        int fd;
        struct flock lock;

        fd = open("file1.txt", O_RDONLY);

        lock.l_type = F_RDLCK; // write lock 
        lock .l_whence = SEEK_SET;
        lock. l_start - 0;
        lock. l_len = 0;

        printf("Trying for read lock\n");
        fcntl(fd, F_SETLKW, &lock);

        printf("Read lock is there press Enter key to release... otherwise keep remain silent!!\n");

        getchar();

        lock.l_type = F_UNLCK;

        fcntl(fd, F_SETLK, &lock);

        printf("Read lock relased Enjoy and chill!!\n");

        close(fd);

        return 0;
}
/*

OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que16$ ./a.out
Trying for read lock
Read lock is there press Enter key to release... otherwise keep remain silent!!
*/
