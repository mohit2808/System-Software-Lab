// Roll Num : MT2024137
// Name : Shah Mohit P
//33. Write a program to communicate between two machines using socket.
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
    struct sockaddr_in serv;

    int sd;
    char buff[50];
    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5055);

    connect(sd, (void*) (&serv), sizeof(serv));
    write(sd, "Hello Server\n", 14);
    read(sd, buff, sizeof(buff));
    printf("Message from Server: %s\n", buff);

}

//OUTPUT
// Termianl 1:
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 33server.c 
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message from Client: Hello Server

// Terminal 2:
// mohit@mohit-14IRL8:~$ cd SSHandsOnList2
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 33client.c 
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Message from Server: ACK from Server