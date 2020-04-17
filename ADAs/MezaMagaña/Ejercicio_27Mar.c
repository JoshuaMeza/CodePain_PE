/*
    Author Joshua Immanuel Meza Magaña
    Version 1.0.0
    Date 27/03/2020
    Program who read and print an array with pointers
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

void readArr(int (*)[N]);
void printArr(int (*)[N]);

int main(){
    int x[N][N];

    readArr(x);

    printArr(x);

    return 0;
}

void readArr(int (*x)[N]){
    int i,j;
    time_t t;

    srand((unsigned) time(&t));

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            *(*(x+i)+j)=rand()%10;
        }
    }
}

void printArr(int (*x)[N]){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d  ",*(*(x+i)+j));
        }
        printf("\n");
    }
}