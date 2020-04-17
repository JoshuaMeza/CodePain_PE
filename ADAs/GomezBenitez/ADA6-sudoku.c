//Programa que crea una matriz de 9x9 y determina si es un sudoku
//Realizado por: Jonathan Gómez Benítez
//Versión 1.0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Se definen la estructura y la palabra tablero, la cual contiene el sudoku que tiene 3 cuadros de 3x3
typedef struct tablero{
    int sudoku[3][3];
}tablero;

//Se definen las funciones que serán utilizadas para asignar de manera aleatoria los valores al sudoku, comprobarlo e imprimirlo
void asignarSudoku(tablero tableroMenor[][3]);
void imprimirSudoku(tablero tableroMenor[][3]);
void revisarTablerosMenores(tablero tableroMenor[][3], int*comprobador);
void revisarFilas(tablero tableroMenor[][3], int*comprobador);
void revisarColumnas(tablero tableroMenor[][3], int*comprobador);
void imprimirComprobador(int comprobador);

int main(){
    //Se definen las variables comprobador (que será 1 si el tablero si es sudoku y 0 si no lo es) y tablero menor
    //que son los cuadros de 3x3 que conforman el sudoku.
    int comprobador=1;
    tablero tableroMenor[3][3];
    //Se incluyen las funciones para que se ejecuten y realicen su tarea.
    asignarSudoku(tableroMenor);
    imprimirSudoku(tableroMenor);
    revisarTablerosMenores(tableroMenor,&comprobador);
    revisarFilas(tableroMenor,&comprobador);
    revisarColumnas(tableroMenor,&comprobador);
    imprimirComprobador(comprobador);
}

//De forma "aleatoria", usando 4 ciclos for se llenan todos los tableros menores dentro del tablero principal
void asignarSudoku(tablero tableroMenor[][3]){
    time_t t;
    srand((unsigned) time(&t));
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            for(int j=0;j<3;j++){
                for(int l=0;l<3;l++){
                    tableroMenor[i][j].sudoku[k][l]=rand()%10;
                }
            }
        }
    }
}

//Se comprueba que dentro los tableros menores no exista el mismo número más de una vez, de ser así el valor del
//comprobador se modifica a 0, es decir, no es un sudoku.
void revisarTablerosMenores(tablero tableroMenor[][3], int*comprobador){
    int contador;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            contador=0;
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(tableroMenor[i][j].sudoku[i][j]==tableroMenor[i][j].sudoku[k][l]){
                        contador++;
                    }
                }
            if(contador>0){
                *comprobador=0;
            }     
            }
        }
    }
}

//Se revisan las filas con la posición de cada tablero menor y se compara con el resto del sudoku, en caso de existir
//el mismo número más de una vez en cualquier fila, el comprobador modifica su valor.
void revisarFilas(tablero tableroMenor[][3], int*comprobador){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                   if(tableroMenor[0][j].sudoku[i][j]==tableroMenor[1][j].sudoku[k][j] || tableroMenor[0][j].sudoku[i][j]==tableroMenor[2][j].sudoku[k][j]){
                    *comprobador=0;
                }
                }  
        }
    } 
}

//Se revisan las columnas de los tableros menores comparandolos entre si y en caso de encontrar un mismo número más de una
//vez el valor del comprobador cambia a 0.
void revisarColumnas(tablero tableroMenor[][3], int*comprobador){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
                for(int l=0;l<3;l++){
                   if(tableroMenor[i][0].sudoku[i][j]==tableroMenor[i][1].sudoku[i][l] || tableroMenor[i][0].sudoku[i][j]==tableroMenor[i][2].sudoku[i][l]){
                    *comprobador=0;
                }
                }  
        }
    } 
}

//Imprime el sudoku completo con la ayuda de 4 ciclos for, 2 para imprimir "sudoku" y los otros 2 para imprimir los tableros
//dentro de "sudoku".
void imprimirSudoku(tablero tableroMenor[][3]){
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            for(int j=0;j<3;j++){
                for(int l=0;l<3;l++){
                    printf("%d  ",tableroMenor[i][j].sudoku[k][l]);
                }
            }
            printf("\n");
        }
    }
}

//En caso de que el comprobador siga siendo 1, el tablero es un sudoñu, cuando es 0 no lo es, se imprime el resultado.
void imprimirComprobador(int comprobador){
    if (comprobador==0){
        printf("\nNo es un sudoku");
    } else {
        printf("\nSi es un sudoku");
    }
}
