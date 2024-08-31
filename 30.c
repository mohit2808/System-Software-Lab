/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *30. Write a program to run a script at a specific time using a Daemon process.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int init_daemon() {
    int pid = fork();
    if (pid > 0) return 0;
    if (pid < 0) return -1;
    pid = getpid();

    setsid();
    umask(0);
    int fd = open(".log", O_RDWR | O_CREAT | O_APPEND, 0777);
    char msg[128] = {0};
    sprintf(msg, "[%d] daemon started at %ld\n", pid, time(NULL));
    write(fd, msg, sizeof(msg));
    long int init_time = time(NULL);
    while (1) {
        sprintf(msg, "[%d] daemon still running at %ld\n", pid, time(NULL));
        write(fd, msg, sizeof(msg));
        system("sh 30.sh");
        sleep(10);
        if (init_time > 0 && time(NULL) - init_time > 30) {
            system("sh 30.sh Hello");
            init_time = -1;
        }
    }
    return 0;    
}

int main(void) {
    return init_daemon();
}

// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out &
// [1] 7877
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cat .log
// [7432] daemon started at 1725125882
// [7432] daemon still running at 1725125882
// [7432] daemon still running at 1725125892
// [7432] daemon still running at 1725125902
// [7432] daemon still running at 1725125912
// [7432] daemon still running at 1725125922
// [7432] daemon still running at 1725125932
// [7432] daemon still running at 1725125942
// [7432] daemon still running at 1725125952
// [7432] daemon still running at 1725125962
// [7432] daemon still running at 1725125972
// [7432] daemon still running at 1725125982
// [7432] daemon still running at 1725125992
// [7432] daemon still running at 1725126002
// [7432] daemon still running at 1725126012
// [7432] daemon still running at 1725126022
// [7432] daemon still running at 1725126032
// [7432] daemon still running at 1725126042
// [7432] daemon still running at 1725126052
// [7432] daemon still running at 1725126062
// [7432] daemon still running at 1725126072
// [7432] daemon still running at 1725126082
// [7432] daemon still running at 1725126092
// [7432] daemon still running at 1725126102
// [7432] daemon still running at 1725126112
// [7432] daemon still running at 1725126122
// [7432] daemon still running at 1725126132
// [7432] daemon still running at 1725126142
// [7738] daemon started at 1725126150
// [7738] daemon still running at 1725126150
// [7432] daemon still running at 1725126152
// [7738] daemon still running at 1725126160
// [7432] daemon still running at 1725126162
// [7738] daemon still running at 1725126170
// [7432] daemon still running at 1725126172
// [7738] daemon still running at 1725126180
// [7432] daemon still running at 1725126182
// [7738] daemon still running at 1725126190
// [7432] daemon still running at 1725126192
// [7738] daemon still running at 1725126200
// [7432] daemon still running at 1725126202
// [7738] daemon still running at 1725126210
// [7432] daemon still running at 1725126212
// [7738] daemon still running at 1725126220
// [7432] daemon still running at 1725126222
// [7738] daemon still running at 1725126230
// [7432] daemon still running at 1725126232
// [7738] daemon still running at 1725126240
// [7878] daemon started at 1725126241
// [7878] daemon still running at 1725126241
// [7432] daemon still running at 1725126242
// [7738] daemon still running at 1725126250
// [7878] daemon still running at 1725126251
// [7432] daemon still running at 1725126252
// [7738] daemon still running at 1725126260
// [7878] daemon still running at 1725126261
// [7432] daemon still running at 1725126262
// [1]+  Done                    ./a.out
