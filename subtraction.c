#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	int result = num2 - num1;
	printf("%d - %d = %d\n", num2 ,num1, result);

	return 0;
}
