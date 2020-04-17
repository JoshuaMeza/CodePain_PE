//Programa que genera una matriz de N*N con números aleatorios de 0 a 10.
//Realizado por: Jonathan Gregorio Gómez Benítez.
//Versión 2.0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
void asignarArreglo(int (*arreglo)[N]);
void imprimirArreglo(int (*arreglo)[N]);
int main () {
   int arreglo[N][N];
   time_t t;
   /* Inicializa el generador de números aleatorios */
   srand((unsigned) time(&t));
   asignarArreglo(arreglo);
   imprimirArreglo(arreglo);
   return(0);
}
//Asigna a cada espacio de la matriz un número aleatorio entre 0 y 10
void asignarArreglo(int (*arreglo)[N]) {
    for(int i = 0; i < N; i++) {
        for ( int j=0; j< N; j++) {
         *(*(arreglo+i)+j) = rand() % 10;
        }
    }}
//Imprime la matriz completa, la cual servirá para comprobar el resto de funciones
void imprimirArreglo(int (*arreglo)[N]) {
    for(int i = 0; i < N; i++) {
        for ( int j=0; j<N; j++) {
          printf("%d ", *(*(arreglo+i)+j));
        }
        printf("\n");
    }
    printf("\n");
}
