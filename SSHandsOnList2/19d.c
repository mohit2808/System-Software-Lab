// Roll Num : MT2024137
// Name : Shah Mohit P
// 19. Create a FIFO file by
// a. mknod command
// b. mkfifo command
// c. use strace command to find out, which command (mknod or mkfifo) is better.
// c. mknod system call
// d. mkfifo library function
#include<sys/stat.h>

int main(){
    mknod("fifotest3", S_IFIFO | 0777, 0);
}
//OUTPUT
// prwxrwxr-x  1 mohit mohit     0 Sep 20 00:56 fifotest3|

//OUTPUT with commands of 19a, 19b, 19c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ mkfifo fifotest1
// mohit@mohit-14IRL8:~/SSHandsOnList2$ mknode fifotest2 p
// prw-rw-r--  1 mohit mohit     0 Sep 20 00:36  fifotest1|
// prw-rw-r--  1 mohit mohit     0 Sep 20 00:37  fifotest2|
//mknod is better than mkfifo as the mkfifo uses the mknod in the background to create fifo file
