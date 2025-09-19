/*
============================================================================================================================================================
Name : 27.c
Author : Gaurav Rajpurohit
Description: Write a program to execute ls -Rl using execl, execlp, execle, execv, and execvp system calls.
Date: Sept 6th, 2025.
============================================================================================================================================================
*/





#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){

	if (strcmp(argv[1], "execl") == 0)
    {
        execl("/bin/ls", "ls", "-Rl", NULL);
    }
    else if (strcmp(argv[1], "execlp") == 0)
    {
        execlp("ls", "ls", "-Rl", NULL);
    }
    else if (strcmp(argv[1], "execle") == 0)
    {
        char *envp[] = {"PATH=/bin", NULL};
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
    }
    else if (strcmp(argv[1], "execv") == 0)
    {
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
    }
    else if (strcmp(argv[1], "execvp") == 0)
    {
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
    }

    return 0;
}

/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que27$ ./a.out execl
.:
total 20
-rw-rw-r-- 1 gaurav176 gaurav176   715 Sep  6 16:32 27.c
-rwxrwxr-x 1 gaurav176 gaurav176 16224 Sep  6 16:32 a.out
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que27$ ./a.out execp
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/hands-on-list/que27$ ./a.out execlp
.:
total 20
-rw-rw-r-- 1 gaurav176 gaurav176   715 Sep  6 16:32 27.c
-rwxrwxr-x 1 gaurav176 gaurav176 16224 Sep  6 16:32 a.out
*/
