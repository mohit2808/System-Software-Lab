#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int fd;
    struct{
        int ticket_no;
    }db;

    db.ticket_no = 3;

    fd = open("db", O_CREAT|O_RDWR, 0744);
    write(fd, &db, sizeof(db));
    close(fd);
    fd = open("db", O_RDONLY);
    read(fd, &db, sizeof(db));
    printf("Ticket Number : %d\n", db.ticket_no);
    close(fd);

}