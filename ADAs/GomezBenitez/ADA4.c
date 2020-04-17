//Programa que genera una matriz de N*N con números aleatorios de 0 a 10.
//Realizado por: Jonathan Gregorio Gómez Benítez.
//Versión 2.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

//Se declaran las funciones que se usan en el código. Cada una tiene el nombre de la sección o secciones que recorre.
void asignarArreglo(int arreglo[N][N]);
void imprimirArreglo(int arreglo[N][N]);
void imprimirDiagonalPrincipal(int arreglo [N][N]);
void imprimirDiagonalPrincipalinversa(int arreglo [N][N]);
void RecorrerMatriz1a2Ascendente(int arreglo [N][N]);
void RecorrerMatriz1a2Descendente(int arreglo[N][N]);
void RecorrerMatriz1a4Ascendente(int arreglo[N][N]);
void RecorrerMatriz1a4Descendente(int arreglo[N][N]);
void RecorrerMatriz3a4Ascendente(int arreglo[N][N]);
void RecorrerMatriz3a4Descendente(int arreglo[N][N]);
void RecorrerMatriz2a3Ascendente(int arreglo[N][N]);
void RecorrerMatriz2a3Descendente(int arreglo[N][N]);
void RecorrerMatriz1Ascendente(int arreglo[N][N]);
void RecorrerMatriz1Descendente(int arreglo[N][N]);
void RecorrerMatriz2Ascendente(int arreglo[N][N]);
void RecorrerMatriz2Descendente(int arreglo[N][N]);
void RecorrerMatriz3Ascendente(int arreglo[N][N]);
void RecorrerMatriz3Descendente(int arreglo[N][N]);
void RecorrerMatriz4Ascendente(int arreglo[N][N]);
void RecorrerMatriz4Descendente(int arreglo[N][N]);
int main () {
   int arreglo[N][N];
   time_t t;
   /* Inicializa el generador de números aleatorios */
   srand((unsigned) time(&t));
   //Imprime las diferentes funciones, las cuales se ejecutan de manera automática siguiendo el orden siguiente: 
   asignarArreglo(arreglo);
   imprimirArreglo(arreglo);
   imprimirDiagonalPrincipal(arreglo);
   imprimirDiagonalPrincipalinversa(arreglo);
   RecorrerMatriz1a2Ascendente(arreglo);
   RecorrerMatriz1a2Descendente(arreglo);
   RecorrerMatriz1a4Ascendente(arreglo);
   RecorrerMatriz1a4Descendente(arreglo);
   RecorrerMatriz3a4Ascendente(arreglo);
   RecorrerMatriz3a4Descendente(arreglo);
   RecorrerMatriz2a3Ascendente(arreglo);
   RecorrerMatriz2a3Descendente(arreglo);
   RecorrerMatriz1Ascendente(arreglo);
   RecorrerMatriz1Descendente(arreglo);
   RecorrerMatriz2Ascendente(arreglo);
   RecorrerMatriz2Descendente(arreglo);
   RecorrerMatriz3Ascendente(arreglo);
   RecorrerMatriz3Descendente(arreglo);
   RecorrerMatriz4Ascendente(arreglo);
   RecorrerMatriz4Descendente(arreglo);
   return(0);
}
//Asigna a cada espacio de la matriz un número aleatorio entre 0 y 10
void asignarArreglo(int arreglo [][N]) {
    for(int i = 0; i < N; i++) {
        for ( int j=0; j< N; j++) {
         arreglo[i][j] = rand() % 10;
        }
    }}
//Imprime la matriz completa, la cual servirá para comprobar el resto de funciones
void imprimirArreglo(int arreglo[][N]) {
    for(int i = 0; i < N; i++) {
        for ( int j=0; j<N; j++) {
          printf("%d ",arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime la diagonal principal de la matriz, es decir, cuando i==j
void imprimirDiagonalPrincipal(int arreglo[][N]){
    for(int i = 0; i < N; i++) {
        for ( int j= 0; j<N; j++) {
          if (i==j){
              printf("%d ",arreglo[i][j]);
          } else {
              printf("  ");
          }
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime la diagonal principal inversa, es decir, empezando con la última i==j y terminando con la primera
void imprimirDiagonalPrincipalinversa (int arreglo[][N]){
    for(int i = N-1; i>=0; i--) {
        for ( int j= N-1; j>=0; j--) {
          if (i==j){
              printf("%d ",arreglo[i][j]);
          } else {
              printf("  ");
          }
        }
        printf("\n");
    }
    printf("\n");

}
//Imprime las secciones 1-2 de la matriz de forma ascendente, básicamente en cada columna imprime hasta que j<=(N-1-i)
void RecorrerMatriz1a2Ascendente(int arreglo[][N]){
    for (int i=0; i <N; i++){
        for ( int j=0; j<(N-i); j++){
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las secciones 1-2 de la matriz de forma descendente, básicamente en cada columna imprime hasta que j<=(N-1-i)
// pero empezando desde la última fila hasta la primera.
void RecorrerMatriz1a2Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for ( int j=0; j<=(N-1-i); j++){
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las secciones 1-4 de la matriz de forma ascendente, básicamente en cada columna imprime hasta que (N+1-j)>(N-i)
void RecorrerMatriz1a4Ascendente(int arreglo[][N]){
    for (int i=0; i <N; i++){
        for ( int j=0; (N+1-j)>(N-i); j++){
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las secciones 1-4 de la matriz de forma descendente, básicamente en cada columna imprime hasta que (N+1-j)>(N-i)
// pero empezando desde la última fila hasta la primera.
void RecorrerMatriz1a4Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for ( int j=0; (N-1-j)>=(N-1-i); j++){
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las secciones 3-4 de la matriz de forma ascendente, básicamente en cada columna imprime hasta que (N-1)<=(j+i)
// empezadando desde la última columna hasta la primera
void RecorrerMatriz3a4Ascendente(int arreglo[][N]){
    for (int i=0; i<N; i++){
        for ( int j=N-1; (N-1)<=(j+i); j--){
             printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las secciones 1-4 de la matriz de forma descendente, básicamente en cada columna imprime hasta que (N-1)<=(j+i)
// pero empezando desde la última fila hasta la primera.
void RecorrerMatriz3a4Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for ( int j=N-1; (N-1)<=(j+i); j--){
             printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las secciones 2-3 de la matriz de forma ascendente, básicamente en cada columna imprime hasta que j>=i empezando
//desde la última columna hasta la primera
void RecorrerMatriz2a3Ascendente(int arreglo[][N]){
    for (int i=0; i<N;i++){
        for ( int j=N-1; j>=i; j--){
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las secciones 2-3 de la matriz de forma descendente, básicamente en cada columna imprime hasta que j>=i empezando
//desde la última fila y columna hasta las primeras
void RecorrerMatriz2a3Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for ( int j=N-1;j>=i; j--){
            printf("%d ", arreglo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las sección 1 de la matriz de forma ascendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz1Ascendente(int arreglo[][N]){
    for (int i=0; i<N; i++){
        for ( int j=0;j<N; j++){
            if (j>=1){
                if (i>=j & i<=(N-1-j)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf(" ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n"); 
}
//Imprime las sección 1 de la matriz de forma descendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz1Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for ( int j=0;j<N; j++){
            if (j>=1){
                if (i>=j & i<=(N-1-j)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf(" ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}//Imprime las sección 2 de la matriz de forma ascendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz2Ascendente(int arreglo[][N]){
    for (int i=0; i<N; i++){
        for ( int j=0;j<N; j++){
            if (i>=1){
                if (j>=i & j<=(N-1-i)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf("  ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
}//Imprime las sección 2 de la matriz de forma descendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz2Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for ( int j=0;j<N; j++){
            if (i>=1){
                if (j>=i & j<=(N-1-i)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf("  ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las sección 3 de la matriz de forma ascendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz3Ascendente(int arreglo[][N]){
    for (int i=0; i<N; i++){
        for ( int j=N-1; (N-1)<=(j+i); j--){
            if (j>=0){
                if (i<=j & i>=(N-1-j)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf(" ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las sección 3 de la matriz de forma descendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz3Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for ( int j=N-1; (N-1)<=(j+i); j--){
            if (j>=0){
                if (i<=j & i>=(N-1-j)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf(" ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
}
//Imprime las sección 4 de la matriz de forma ascendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz4Ascendente(int arreglo[][N]){
    for (int i=0; i<N; i++){
        for (int j=0; (N+1-j)>(N-i); j++){
            if (i>=0){
                if (j<=i & j>=(N-1-i)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf("  ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
//Imprime las sección 4 de la matriz de forma descendente, básicamente en cada columna imprime los valores i>=j & i<=(N-1-j) 
void RecorrerMatriz4Descendente(int arreglo[][N]){
    for (int i=N-1; i>=0; i--){
        for (int j=0; (N+1-j)>(N-i); j++){
            if (i>=0){
                if (j<=i & j>=(N-1-i)){
                printf("%d ", arreglo[i][j]);
            } else {
                printf("  ");
            }
            } else {
                printf("%d ",arreglo[i][j]);
            }
        }
        printf("\n");
    }
}
