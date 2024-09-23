// Roll Num : MT2024137
// Name : Shah Mohit P
//33. Write a program to communicate between two machines using socket.
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){

    struct sockaddr_in serv, cli;//Structure in netinet/in.h

    int sd, sz, nsd;
    char buff[50];

    sd = socket(AF_UNIX, SOCK_STREAM, 0); 

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY; //with INADDR_ANY it can serve any address
    serv.sin_port = htons(5055); //htons converts little endian to big endian type

    bind(sd, (void *)&serv, sizeof(serv));

    listen(sd, 5);//Limit for second argument is from 1 to 5 because at a time 

    sz = sizeof(cli);
    nsd = accept(sd, (void*)(&cli), &sz);
    read(nsd, buff, sizeof(buff));
    printf("Message from Client: %s\n", buff);
    write(nsd, "ACK from Server\n", 17);
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

