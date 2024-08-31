#include<stdio.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Not enough arguments\n");
        return 0;
    }

    printf("%s, %s\n", argv[1], argv[2]);
}