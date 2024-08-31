/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *20. Find out the priority of your running program. Modify the priority with nice command.
 
*/

#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<sys/resource.h>


int main(){

    int crPrio = getpriority(PRIO_PROCESS, 0);// Gets the process priority and the 0 in argument means the parent process
    
    printf("Current priority : %d\n", crPrio); // It will print zero because the default nice value is zero
    
    int new_pid = nice(5); //This assigns the nice value ie priority to the curreny process. Its range is -20 to 19 

    printf("Priority Changed to : %d\n", new_pid);

    int newPrio = getpriority(PRIO_PROCESS, 0);

    printf("New Priority : %d\n", newPrio);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Current priority : 0
// Priority Changed to : 5
// New Priority : 5
