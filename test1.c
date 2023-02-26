/*

create file pointer and call a func that calls fillBuffer() many times 
and each time the buffer is filled, it prints the buffer info and location of fp



*/

#include<stdio.h>
#include<stdlib.h>
#include"test1.h"



int main(int argc, char* argv[]) {
    if(argc != 3) exit(1);
    FILE *fp = fopen(argv[1], "r");
    int len = atoi(argv[2]);

    initLex(fp, len);

}