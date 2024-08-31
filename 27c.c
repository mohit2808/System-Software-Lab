/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    if (fork() == 0) {
        return execle("/bin/ls", "ls", "-Rl", NULL, __environ);
    }

    wait(0);
    return 0;
}


// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 27c.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// .:
// total 288
// -rw-rw-r-- 1 mohit mohit   697 Aug 29 01:40 10.c
// -rw-rw-r-- 1 mohit mohit   803 Aug 29 01:42 11.c
// -rw-rw-r-- 1 mohit mohit   348 Aug 29 01:43 12.c
// -rw-rw-r-- 1 mohit mohit  1066 Aug 29 01:44 13.c
// -rw-rw-r-- 1 mohit mohit  1439 Aug 29 01:45 14.c
// -rw-rw-r-- 1 mohit mohit    14 Aug 28 01:54 14.sh
// -rw-rw-r-- 1 mohit mohit  3922 Aug 29 01:45 15.c
// -rw-rw-r-- 1 mohit mohit   927 Aug 28 15:03 16a.c
// -rw-rw-r-- 1 mohit mohit  1019 Aug 28 15:04 16b.c
// -rw-rw-r-- 1 mohit mohit  1557 Aug 30 17:06 17_ticket_locking.c
// -rw-rw-r-- 1 mohit mohit   429 Aug 30 14:40 17_ticket_no.c
// -rw-rw-r-- 1 mohit mohit   469 Aug 30 19:39 18_record_create.c
// -rw-rw-r-- 1 mohit mohit  1740 Aug 30 20:16 18_record_locking.c
// -rw-rw-r-- 1 mohit mohit   582 Aug 31 03:35 19.c
// -rw-rw-r-- 1 mohit mohit   720 Aug 29 09:15 1_a.c
// -rw-rw-r-- 1 mohit mohit   683 Aug 29 09:19 1_b.c
// -rw-rw-r-- 1 mohit mohit   804 Aug 29 23:45 1_c.c
// -rw-rw-r-- 1 mohit mohit   874 Aug 31 16:20 20.c
// -rw-rw-r-- 1 mohit mohit   619 Aug 31 16:36 21.c
// -rw-rw-r-- 1 mohit mohit   801 Aug 31 17:01 22.c
// -rw-rw-r-- 1 mohit mohit   576 Aug 31 17:14 23.c
// -rw-rw-r-- 1 mohit mohit   553 Aug 31 17:20 24.c
// -rw-rw-r-- 1 mohit mohit  1411 Aug 31 18:08 25.c
// -rw-rw-r-- 1 mohit mohit   704 Aug 31 18:51 26a.c
// -rw-rw-r-- 1 mohit mohit   747 Aug 31 18:53 26b.c
// -rw-rw-r-- 1 mohit mohit   209 Aug 31 18:56 27a.c
// -rw-rw-r-- 1 mohit mohit   205 Aug 31 18:56 27b.c
// -rw-rw-r-- 1 mohit mohit   221 Aug 31 18:57 27c.c
// -rw-rw-r-- 1 mohit mohit   240 Aug 31 18:58 27d.c
// -rw-rw-r-- 1 mohit mohit   241 Aug 31 19:00 27e.c
// -rw-rw-r-- 1 mohit mohit   295 Aug 29 01:32 2.c
// -rw-rw-r-- 1 mohit mohit   514 Aug 29 01:33 3.c
// -rw-rw-r-- 1 mohit mohit   538 Aug 29 01:34 4.c
// -rw-rw-r-- 1 mohit mohit   463 Aug 29 01:35 5.c
// -rw-rw-r-- 1 mohit mohit   438 Aug 29 01:36 6.c
// -rw-rw-r-- 1 mohit mohit   606 Aug 29 01:37 7.c
// -rw-rw-r-- 1 mohit mohit   537 Aug 29 01:38 8.c
// -rw-rw-r-- 1 mohit mohit  1066 Aug 29 01:39 9.c
// -rwxrwxr-x 1 mohit mohit 16080 Aug 31 19:01 a.out
// -rwxr--r-- 1 mohit mohit     5 Aug 30 16:59 db
// -rw-rw-r-- 1 mohit mohit    48 Aug 21 23:04 f1.c
// -rw-rw-r-- 1 mohit mohit    63 Aug 21 23:06 f2.c
// -rwxrwxr-x 1 mohit mohit 16840 Aug 29 23:49 f3
// -rw-rw-r-- 1 mohit mohit    63 Aug 21 23:06 f3.c
// -rw-rw-r-- 1 mohit mohit    63 Aug 21 23:06 f4.c
// -rw-rw-r-- 1 mohit mohit    63 Aug 21 23:06 f5.c
// prwxrwxr-x 1 mohit mohit     0 Aug 15 01:49 fifofile1
// prwxrwxr-x 1 mohit mohit     0 Aug 29 09:21 fifotest
// -rw-rw-r-- 1 mohit mohit    51 Aug 22 08:40 file_1
// -rwxrwxrwx 2 mohit mohit    31 Aug 22 09:14 file1
// -rw-rw-r-- 1 mohit mohit    20 Aug 25 01:28 file10
// -rw-rw-r-- 1 mohit mohit     0 Aug 25 01:40 file11
// -rw-rw-r-- 1 mohit mohit    63 Aug 28 14:46 file16a
// -rw-rw-r-- 1 mohit mohit     0 Aug 28 14:58 file16b
// -rw-rw-rw- 2 mohit mohit     0 Aug 11 22:25 file2
// -rw-rw-r-- 1 mohit mohit    29 Aug 31 17:00 file22
// -rwxrwxr-x 1 mohit mohit 15952 Aug 31 18:49 file26a
// -rw-rw-r-- 1 mohit mohit    80 Aug 31 18:34 file26a.c
// -rwxrwxr-x 1 mohit mohit 16000 Aug 31 18:51 file26b
// -rw-rw-r-- 1 mohit mohit   181 Aug 31 18:44 file26b.c
// -rwxrwxrwx 2 mohit mohit    31 Aug 22 09:14 hardlink
// -rw-rw-rw- 2 mohit mohit     0 Aug 11 22:25 hardlink1
// -rw-rw-r-- 1 mohit mohit     0 Aug 10 22:07 hrdlnk
// -rw-rw-r-- 1 mohit mohit     0 Aug 25 02:12 README.md
// -rw-rw-r-- 1 mohit mohit    24 Aug 30 20:10 record.txt
// lrwxrwxrwx 1 mohit mohit     4 Aug 10 22:07 sftlnk -> test
// lrwxrwxrwx 1 mohit mohit     5 Aug 11 22:18 softlink1 -> file1
// lrwxrwxrwx 1 mohit mohit     5 Aug 11 22:46 softlink2 -> file1
// lrwxrwxrwx 1 mohit mohit     5 Aug 29 09:13 softlink3 -> file1
// -rw------- 1 mohit mohit    31 Aug 23 16:06 test7
// -rw-rw-r-- 1 mohit mohit    27 Aug 22 01:26 testfile
// -rw-rw-r-- 1 mohit mohit     0 Aug 21 22:30 trial
