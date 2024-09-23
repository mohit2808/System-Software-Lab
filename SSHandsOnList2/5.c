// Roll Num : MT2024137
// Name : Shah Mohit P
// 5. Write a program to print the system limitation of
// a. maximum length of the arguments to the exec family of functions.
// b. maximum number of simultaneous process per user id.
// c. number of clock ticks (jiffy) per second.
// d. maximum number of open files
// e. size of a page
// f. total number of pages in the physical memory
// g. number of currently available pages in the physical memory.
#include<limits.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/sysinfo.h>

int main(){
    
    long max_arg_length = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to the exec family of functions: %ld\n", max_arg_length);

    long max_processes_per_user = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user ID: %ld\n", max_processes_per_user);

    long clock_ticks_per_sec = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second: %ld\n", clock_ticks_per_sec);

    long max_open_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", max_open_files);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    struct sysinfo info;
    sysinfo(&info);
    long total_pages = info.totalram / page_size;
    printf("Total number of pages in physical memory: %ld\n", total_pages);

    long available_pages = info.freeram / page_size;
    printf("Number of currently available pages in physical memory: %ld\n", available_pages);

}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 5.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Maximum length of arguments to the exec family of functions: 2097152
// Maximum number of simultaneous processes per user ID: 62585
// Number of clock ticks per second: 100
// Maximum number of open files: 1048576
// Size of a page: 4096 bytes
// Total number of pages in physical memory: 4023264
// Number of currently available pages in physical memory: 1505527