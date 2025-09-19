/*
============================================================================
Name : 2.c
Author : Gaurav Rajpurohit
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 14th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    
    while (1) {
        sleep(1); 
    }
    return 0;
}

/*
OUTPUT 
first do compile then run this ./a.out & to get process id(x) then top -p x.

5743 gaurav1+  20   0    2548   1304   1304 S   0.0   0.0   0:00.00 a.out                                                                                                            

*/