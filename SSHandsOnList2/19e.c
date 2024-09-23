// Roll Num : MT2024137
// Name : Shah Mohit P
//19. Create a FIFO file by
// a. mknod command
// b. mkfifo command
// c. use strace command to find out, which command (mknod or mkfifo) is better.
// c. mknod system call
// d. mkfifo library function
#include<sys/types.h>
#include<sys/stat.h>

int main(){

    mkfifo("fifotest4", 0777);
}

//OUTPUT
// prwxrwxr-x  1 mohit mohit     0 Sep 20 00:59 fifotest4|