/*
    Autor Joshua Immanuel Meza Magaña
    Versión 1.0.0
    Fecha 23/03/2020
    Programa que imprime las tablas pedidas SIN FORMATO.
*/
#include <stdio.h>
#define N 3

int generarMatriz(int arr[][N]);
void recorrerMatriz12Ascendente(int arr[][N]);
void recorrerMatriz12Descendente(int arr[][N]);
void recorrerMatriz34Ascendente(int arr[][N]);
void recorrerMatriz34Descendente(int arr[][N]);
void recorrerMatriz14Ascendente(int arr[][N]);
void recorrerMatriz14Descendente(int arr[][N]);
void recorrerMatriz23Ascendente(int arr[][N]);
void recorrerMatriz23Descendente(int arr[][N]);
void recorrerMatriz1Ascendente(int arr[][N]);
void recorrerMatriz1Descendente(int arr[][N]);
void recorrerMatriz2Ascendente(int arr[][N]);
void recorrerMatriz2Descendente(int arr[][N]);
void recorrerMatriz3Ascendente(int arr[][N]);
void recorrerMatriz3Descendente(int arr[][N]);
void recorrerMatriz4Ascendente(int arr[][N]);
void recorrerMatriz4Descendente(int arr[][N]);
void recorrerDiagonalPrincipal(int arr[][N]);
void recorrerDiagonalInvertida(int arr[][N]);

int main(){
    int arr[N][N];

    generarMatriz(arr);
    recorrerMatriz12Ascendente(arr);
    recorrerMatriz12Descendente(arr);
    recorrerMatriz34Ascendente(arr);
    recorrerMatriz34Descendente(arr);
    recorrerMatriz14Ascendente(arr);
    recorrerMatriz14Descendente(arr);
    recorrerMatriz23Ascendente(arr);
    recorrerMatriz23Descendente(arr);
    recorrerMatriz1Ascendente(arr);
    recorrerMatriz1Descendente(arr);
    recorrerMatriz2Ascendente(arr);
    recorrerMatriz2Descendente(arr);
    recorrerMatriz3Ascendente(arr);
    recorrerMatriz3Descendente(arr);
    recorrerMatriz4Ascendente(arr);
    recorrerMatriz4Descendente(arr);
    recorrerDiagonalPrincipal(arr);
    recorrerDiagonalInvertida(arr);

    return 0;
}

/* Funciones */

int generarMatriz(int arr[][N]){
    int i, j, con=1;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arr[i][j]=con;
            con++;
        }
    }
}

void recorrerMatriz12Ascendente(int arr[][N]){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N-i;j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz12Descendente(int arr[][N]){
    int i,j;
    
    for(i=N-1;i>=0;i--){
        for(j=0;j<N-i;j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz34Ascendente(int arr[][N]){
    int i,j;
    
    for(i=0;i<N;i++){
        for(j=0;j<N-(N-1-i);j++){
            printf("%d   ",arr[i][j+N-1-i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz34Descendente(int arr[][N]){
    int i,j;
    
    for(i=N-1;i>=0;i--){
        for(j=0;j<N-(N-1-i);j++){
            printf("%d   ",arr[i][j+N-1-i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz14Ascendente(int arr[][N]){
    int i,j;
    
    for(i=0;i<N;i++){
        for(j=0;j<=i;j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz14Descendente(int arr[][N]){
    int i,j;
    
    for(i=N-1;i>=0;i--){
        for(j=0;j<N-(N-1-i);j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz23Ascendente(int arr[][N]){
    int i,j;
    
    for(i=0;i<N;i++){
        for(j=0;j<N-i;j++){
            printf("%d   ",arr[i][j+i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz23Descendente(int arr[][N]){
    int i,j;
    
    for(i=N-1;i>=0;i--){
        for(j=i;j<N;j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz1Ascendente(int arr[][N]){
    int i,j;
    
    for(i=0;i<N/2;i++){
        for(j=0;j<=i;j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    for(i=N/2;i<N;i++){
        for(j=0;j<N-i;j++){
         printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz1Descendente(int arr[][N]){
    int i,j;

    for(i=N-1;i>N/2;i--){
        for(j=0;j<=N-1-i;j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    for(i=N/2;i>=0;i--){
        for(j=0;j<=i;j++){
         printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");   
}

void recorrerMatriz2Ascendente(int arr[][N]){
    int i,j,k;
    
    for(i=0;i<=N/2;i++){
        for(j=0;j<N-2*i;j++){
            for(k=0;k<i;k++){
                printf("    ");
            }
            printf("%d   ",arr[i][j+i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz2Descendente(int arr[][N]){
    int i,j,k;
    
    for(i=N/2;i<N;i++){
        for(j=0;j<N-2*(N-1-i);j++){
            for(k=0;k<N-1-i;k++){
                printf("    ");
            }
            printf("%d   ",arr[N-1-i][j+N-1-i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz3Ascendente(int arr[][N]){
    int i,j;
    
    for(i=0;i<N/2;i++){
        for(j=0;j<=i;j++){
            printf("%d   ",arr[i][N-1-j]);
        }
        printf("\n");
    }
    for(i=N/2;i<N;i++){
        for(j=0;j<N-i;j++){
            printf("%d   ",arr[i][j+i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz3Descendente(int arr[][N]){
    int i,j;
    
    for(i=N-1;i>N/2;i--){
        for(j=0;j<N-i;j++){
            printf("%d   ",arr[i][j+i]);
        }
        printf("\n");
    }
    for(i=N/2;i>=0;i--){
        for(j=0;j<=i;j++){
            printf("%d   ",arr[i][j+N-1-i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz4Ascendente(int arr[][N]){
    int i,j,k;
    
    for(i=N/2;i<N;i++){
        for(j=0;j<N-2*(N-1-i);j++){
            for(k=0;k<N-1-i;k++){
                printf("    ");
            }
            printf("%d   ",arr[i][j+(N-1-i)]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerMatriz4Descendente(int arr[][N]){
    int i,j,k;
    
    for(i=N-1;i>=N/2;i--){
        for(j=0;j<N-2*(N-1-i);j++){
            for(k=0;k<N-1-i;k++){
                printf("    ");
            }
            printf("%d   ",arr[i][j+N-1-i]);
        }
        printf("\n");
    }
    printf("\n");
}

void recorrerDiagonalPrincipal(int arr[][N]){
    int i;
    
    for(i=0;i<N;i++){
        printf("%d",arr[i][i]);
        printf("\n");
    }
    printf("\n");
}

void recorrerDiagonalInvertida(int arr[][N]){
    int i;
    
    for(i=N-1;i>=0;i--){
        printf("%d",arr[i][i]);
        printf("\n");
    }
    printf("\n");
}
