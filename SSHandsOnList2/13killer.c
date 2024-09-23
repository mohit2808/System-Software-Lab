// Roll Num : MT2024137
// Name : Shah Mohit P
// 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
// will send the signal (using kill system call). Find out whether the first program is able to catch
// the signal or not.   
#include<unistd.h>
#include<signal.h>           
#include<stdio.h>

int main(){
    int pid;
    printf("Enter the process Id which is to be stopped : ");
    scanf("%d", &pid);
    
    kill(pid, SIGSTOP);
    printf("Process %d is stopped and gone in the background\n", pid);
    
    sleep(2);
}

//OUTPUT
// Terminal 1:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 13waiting.c 
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Hello
// My PID is : 30470

// [1]+  Stopped                 ./a.out

// TErminal 2:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 13killer.c 
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Enter the process Id which is to be stopped : 30470
// Process 30470 is stopped and gone in the background

// Terminal 1 again:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ fg
// ./a.out
