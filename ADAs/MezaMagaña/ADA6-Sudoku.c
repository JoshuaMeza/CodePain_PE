/*
    Author Joshua Immanuel Meza Magaña
    Version 1.2.0
    Date 05/04/2020
    Program who generates random numbers and verify if it form a sudoku
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

typedef struct sTable{
    int **s;
}sudoku;

void saveMemory(sudoku bTable[][N],int,int);
void genNum(sudoku bTable[][N],int,int,int *);
void checkCell(sudoku bTable[][N],int,int,int *);
void checkLine(sudoku bTable[][N],int,int *);
void checkVer(sudoku bTable[][N],int,int *);
void printTable(sudoku bTable[][N]);
void printIfSud(int);

int main(){
    /* Input */
    sudoku bTable[N][N];
    int i,j,flag=1,mod=1;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            saveMemory(bTable,i,j);
            genNum(bTable,i,j,&mod);
        }
    }

    /* Process */
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            checkCell(bTable,i,j,&flag);
        }
        if(flag==0){
            break;
        }
    }
    for(i=0;i<N;i++){
        if(flag==0){
            break;
        }
        checkLine(bTable,i,&flag);
    }
    for(j=0;j<N;j++){
        if(flag==0){
            break;
        }
        checkVer(bTable,j,&flag);
    }

    /* Output */
    printTable(bTable);
    printIfSud(flag);

    return 0;
}

/* Functions */

void saveMemory(sudoku bTable[][N],int raw,int col){
    /*
    Make the double pointer s a two dimmensional array of pointers
    Args:
        bTable (sudoku): two dimensional array of the structure sTable
        s (int): double pointer used to generate a 2D array 
        raw (int): raws
        col (int): columns
        i (int): counter
        j (int): counter
    Returns: 
        The space of memory for a 2D array
    */
    int i,j;

    bTable[raw][col].s=(int**)malloc(N*sizeof(int));

    for(i=0;i<N;i++){
        bTable[raw][col].s[i]=(int*)malloc(N*sizeof(int));
    }
}

void genNum(sudoku bTable[][N],int raw,int col,int *mod){
    /*
    It fill the 2D array with random numbers
    Args:
        bTable (sudoku): two dimensional array of the structure sTable
        s (int): double pointer used to generate a 2D array 
        raw (int): raw
        col (int): column
        mod (int): pointer of a modificator value
        t (time_t): value of time
        i (int): counter
        j (int): counter
    Returns: 
        The 2D array
    */
    int i,j;
    time_t t;

    srand((unsigned) time(&t));

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            bTable[raw][col].s[i][j]=(rand()*(*mod))%10;
            if(bTable[raw][col].s[i][j]==0){
                bTable[raw][col].s[i][j]+=1;
            }
            /*scanf("%d",&bTable[raw][col].s[i][j]);*/
        }
    }
    *mod+=rand()%10;
}

void checkCell(sudoku bTable[][N],int raw,int col,int *flag){
    /*
    It checks if exist a duplicate number in the small table
    Args:
        bTable (sudoku): two dimensional array of the structure sTable
        s (int): double pointer used to generate a 2D array 
        raw (int): raw
        col (int): column
        i (int): counter for checking raw
        j (int): counter for checking column
        k (int): counter for selected raw
        l (int): counter for selected column
        flag (int): pointer of the flag
    Returns:
        Value of the flag
    */
    int i,j,k,l,con;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            con=0;
            for(k=0;k<N;k++){
                for(l=0;l<N;l++){
                    if(bTable[raw][col].s[i][j]==bTable[raw][col].s[k][l]){
                        con++;
                    }
                }
            }
            if(con>1){
                *flag=0;
            }
        }
    }
}

void checkLine(sudoku bTable[][N],int raw,int *flag){
    /*
    It checks if any number in horizontal direction repeats
    Args:
        bTable (sudoku): two dimensional array of the structure sTable
        s (int): double pointer used to generate a 2D array 
        raw (int): raw
        i (int): counter for checking raw
        j (int): counter for checking column
        l (int): counter for selected column
        flag (int): pointer of the flag
    */
    int i,j,l;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            for(l=0;l<N;l++){
                if(bTable[raw][0].s[i][j]==bTable[raw][1].s[i][l] || bTable[raw][0].s[i][j]==bTable[raw][2].s[i][l]){
                    *flag=0;
                }
            }
        }
    }   
}

void checkVer(sudoku bTable[][N],int col,int *flag){
    /*
    It checks if any number in horizontal direction repeats
    Args:
        bTable (sudoku): Two dimensional array of the structure sTable
        s (int): double pointer used to generate a 2D array 
        col (int): column
        i (int): counter for checking raw
        j (int): counter for checking column
        k (int): counter for selected raw
        flag (int): pointer of the flag
    */
   int i,j,k;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                if(bTable[0][col].s[i][j]==bTable[1][col].s[k][j] || bTable[0][col].s[i][j]==bTable[2][col].s[k][j]){
                    *flag=0;
                }
            }
        }
    }
}

void printTable(sudoku bTable[][N]){
    /*
    It prints the array
    Args:
        bTable (sudoku): Two dimensional array of the structure sTable
        s (int): double pointer used to generate a 2D array 
        i (int): counter for external raws
        j (int): counter for external columns
        k (int): counter for internal raws
        l (int): counter for internal columns
    */
    int i,j,k,l;

    printf("--------- Table ---------\n");
    for(i=0;i<N;i++){
        for(k=0;k<N;k++){
            for(j=0;j<N;j++){
                for(l=0;l<N;l++){
                    printf("%d  ",bTable[i][j].s[k][l]);
                }
            }
            printf("\n");
        }
    }
}

void printIfSud(int flag){
    /*
    It prints if the generated numbers form a sudoku
    Args:
        flag (int): Marks 1 if theres a sudoku, 0 if not
    */
    if(flag==1){
        printf("\nIs a Sudoku!\n");
    }else{
        printf("\nIs not a Sudoku!\n");
    }
}
