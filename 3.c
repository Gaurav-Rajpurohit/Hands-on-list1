/*
============================================================================
Name : 3.c
Author : Gaurav Rajpurohit
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 17th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h>  

int main() {
    int fd;

    
    fd = creat("myfile.txt", 0664);
   

    printf("File created successfully. File descriptor: %d\n", fd);

    
    close(fd);
    return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que3$ ./a.out
File created successfully. File descriptor: 3
*/
