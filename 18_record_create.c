#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
    int i, fd;
    struct{
        int record_num;
        int count;
    }db[3];

    for(int i = 0; i<3; i++){
        db[i].record_num = i+1;
        db[i].count = 0;
    } 

    fd = open("record.txt", O_RDWR);
    write(fd, db, sizeof(db)); //Here db is the array of struct that is why we are giving the name of array
    close(fd);
}