/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *25.Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    int pid_1 = fork();
    if (!pid_1) {
        printf("First Child, PID %d\n", getpid());
        return 0;
    }
    int pid_2 = fork();
    if (!pid_2) {
        printf("Second Child, PID %d\n", getpid());
        return 0;
    }
    int pid_3 = fork();
    if (!pid_3) {
        printf("Favourite Child, PID %d\n", getpid());
        return 0;
    }
    waitpid(pid_3, NULL, 0);
    getchar(); //open the process info by giving command cat /proc/Pid of the process/status | head -n 6 in other terminal
}

// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 25.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// First Child, PID 76183
// Favourite Child, PID 76185
// Second Child, PID 76184

// Terminal 2:
// mohit@mohit-14IRL8:~$ cat /proc/76183/status | head -n 6
// Name:	a.out
// State:	Z (zombie)
// Tgid:	76183
// Ngid:	0
// Pid:	76183
// PPid:	76182
// mohit@mohit-14IRL8:~$ cat /proc/76185/status | head -n 6
// cat: /proc/76185/status: No such file or directory
// mohit@mohit-14IRL8:~$ cat /proc/76184/status | head -n 6
// Name:	a.out
// State:	Z (zombie)
// Tgid:	76184
// Ngid:	0
// Pid:	76184
// PPid:	76182