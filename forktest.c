#include<stdio.h>
#include<unistd.h>

int main(){
	printf("Hello\n");
	fork();
	fork();
}

//OUtput
//Before \n
//mohit@mohit-14IRL8:~/SSHandsOnList1$ cc forktest.c
//mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
//HelloHelloHelloHellomohit@mohit-14IRL8:~/SSHandsOnList1$ vim forktest.c

//After \n
//mohit@mohit-14IRL8:~/SSHandsOnList1$ cc forktest.c
//mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
//Hello
//mohit@mohit-14IRL8:~/SSHandsOnList1$
