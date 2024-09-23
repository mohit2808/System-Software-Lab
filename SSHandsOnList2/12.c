// Roll Num : MT2024137
// Name : Shah Mohit P
// 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
// the parent process from the child process.
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>

int main(){

    if(fork() == 0){
        printf("Hii I am child\n");
        int parentid = getppid();
        kill(parentid, SIGKILL);//when a child's parent is killed then init becomes its parent
        sleep(2);
        printf("I am Orphan\n");
        printf("Press enter to kill me\n");
        getchar();
    }

    else{
        printf("Hii this is Parent\n");
        sleep(10);
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 12.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Hii this is Parent
// Hii I am child
// Killed
// mohit@mohit-14IRL8:~/SSHandsOnList2$ I am Orphan
// Press enter to kill me
