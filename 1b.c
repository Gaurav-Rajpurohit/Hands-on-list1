/*
============================================================================
Name : 1b.c
Author : Gaurav Rajpurohit
Description :Create the following types of a files using (i) shell command (ii) system call
	b. hard link (link system call)
Date: 17th Aug, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>


int main(){
	link("file2.txt","file2_hard.txt");
return 0;}

/*
OUTPUT
-rw-rw-r-- 2 gaurav176 gaurav176     0 Aug 17 14:57 file2_hard.txt


*/