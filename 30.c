/*
============================================================================
Name : 30.c
Author : Gaurav Rajpurohit
Description :30. Write a program to run a script at a specific time using a Daemon process.
Date:  SEPT 6th, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        
        printf("Parent: Child created with PID %d\n", pid);
        exit(EXIT_SUCCESS); 
    } else {
        
        if (setsid() < 0) {
            perror("setsid failed");
            exit(EXIT_FAILURE);
        }

        printf("Child: Running as daemon (PID %d)\n", getpid());

        while (1) {
            time_t cur_time = time(NULL);
            struct tm *t = localtime(&cur_time);

            if (t->tm_hour == 18 && t->tm_min == 34) {
                printf("Child: OPEN DAEMON PROCESS...\n");
                system("./file.sh");
                break;
            }
            sleep(30);
        }
    }

    return 0;
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ cc 30.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ ./a.out
Parent: Child created with PID 10602
Child: Running as daemon (PID 10602)
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ Child: OPEN DAEMON PROCESS...
sh: 1: ./file.sh: Permission denied

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ chmod +x file.sh
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ cc 30.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ cc 30.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ ./a.out
Parent: Child created with PID 10709
Child: Running as daemon (PID 10709)
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que30$ Child: OPEN DAEMON PROCESS...
I AM Gaurav ,HOW ARE YOU????:
BYE BYE!!

*/