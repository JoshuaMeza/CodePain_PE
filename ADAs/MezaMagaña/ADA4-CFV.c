/*
    Author Joshua Immanuel Meza Magaña
    Version 1.1.2
    Date 22/03/2020
    Program who generates a random table NxN and print the section that the user wants
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

int getInstrA();
int getInstrB(int insCheck[2]);
int genArray(int arr[][N],int copyArr[][N]);
int doOne(int copyArr[][N],int insCheck[2],int arr[][N]);
int doTwo(int copyArr[][N],int insCheck[2],int arr[][N]);
int doThree(int copyArr[][N],int insCheck[2],int arr[][N]);
int doFour(int copyArr[][N],int insCheck[2],int arr[][N]);
int doFive(int copyArr[][N],int insCheck[2],int arr[][N]);
int doSix(int copyArr[][N],int insCheck[2],int arr[][N]);
int doSeven(int copyArr[][N],int insCheck[2],int arr[][N]);
int doEight(int copyArr[][N],int insCheck[2],int arr[][N]);
int doNine(int copyArr[][N],int arr[][N]);
int doTen(int copyArr[][N],int arr[][N]);
void printArray(int arr[][N]);
void printResult(int copyArr[][N]);

int main() {
    /* Input */
    int arr[N][N], copyArr[N][N], insCheck[2];

    insCheck[0]=getInstrA();
    insCheck[1]=getInstrB(insCheck);
    
    /* Process */
    genArray(arr,copyArr);
    
    if(insCheck[0]==1){
        doOne(copyArr,insCheck,arr);
    }else if(insCheck[0]==2){
        doTwo(copyArr,insCheck,arr);
    }else if(insCheck[0]==3){
        doThree(copyArr,insCheck,arr);
    }else if(insCheck[0]==4){
        doFour(copyArr,insCheck,arr);
    }else if(insCheck[0]==5){
        doFive(copyArr,insCheck,arr);
    }else if(insCheck[0]==6){
        doSix(copyArr,insCheck,arr);
    }else if(insCheck[0]==7){
        doSeven(copyArr,insCheck,arr);
    }else if(insCheck[0]==8){
        doEight(copyArr,insCheck,arr);
    }else if(insCheck[0]==9){
        doNine(copyArr,arr);
    }else if(insCheck[0]==10){
        doTen(copyArr,arr);
    }

    /* Output */
    printArray(arr);
    printResult(copyArr);

    return 0;
}

/* Functions */

int getInstrA(){
    /*
    Reads the first instruction
    Args:
        insA (int): Instruction A, means what the system will do
    Returns:
        The instruction of what the system will do
    */
    int insA=0;
    
    printf("----------------------------------------------------\n");
    printf("   List of instructions   \n");
    printf("(1) Section 1-2           \n");
    printf("(2) Section 3-4           \n");
    printf("(3) Section 1-4           \n");
    printf("(4) Section 2-3           \n");
    printf("(5) Section 1             \n");
    printf("(6) Section 2             \n");
    printf("(7) Section 3             \n");
    printf("(8) Section 4             \n");
    printf("(9) Main diagonal         \n");
    printf("(10) Inverse diagonal     \n");
    printf("----------------------------------------------------\n");
    printf("What do you want to do?: ");
    scanf("%d",&insA);

    if(insA<1 || insA>10){
        while(insA<1 || insA>10){
            printf("ERROR, TRY AGAIN\n");
            scanf("%d",&insA);
        }
    }

    return insA;
}

int getInstrB(int insCheck[]){
    /*
    Reads the second instruction
    Args:
        insB (int): Instruction B, means in what orientation
    Returns:
        The instruction of which orientation will have the table
    */
    int insB=0;
    
    if(insCheck[0]!=9 && insCheck[0]!=10){
        printf("----------------------------------------------------\n");
        printf("    Orientations   \n");
        printf("(1) Ascending  (2) Descending          \n"); 
        printf("----------------------------------------------------\n");
        printf("Which orientation do you want?: ");
        scanf("%d",&insB);

        if(insB<1 || insB>2){
            while(insB<1 || insB>2){
                printf("ERROR, TRY AGAIN\n");
                scanf("%d",&insB);
            }
        }
    }
    
    return insB;
}

int genArray(int arr[][N], int copyArr[][N]){
    /*
    Generates the array
    Args:
        arr (array): Original random array
        copyArr (array): New array
        i (int): Row
        j (int): Column
    Returns:
        The array
    */
    int i,j;
    time_t t;

    srand((unsigned) time(&t));
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arr[i][j]=rand()%10;
            copyArr[i][j]=-1;
        }
    }
}

int doOne(int copyArr[][N],int insCheck[], int arr[][N]){
    /*
    Do the first sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
    Returns: 
        The new array
    */
    int i,j;

    if(insCheck[1]==1){
        for(i=0;i<N;i++){
            for(j=0;j<N-i;j++){
                copyArr[i][j]=arr[i][j];
            }
        }
    }else{
        for(i=N-1;i>=0;i--){
            for(j=0;j<N-i;j++){
                copyArr[N-1-i][j]=arr[i][j];
            }
        }
    }
}

int doTwo(int copyArr[][N],int insCheck[], int arr[][N]){
     /*
    Do the second sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
    Returns: 
        The new array
    */
    int i,j;

    if(insCheck[1]==1){
        for(i=0;i<N;i++){
            for(j=0;j<N-(N-1-i);j++){
                copyArr[i][j+N-1-i]=arr[i][j+N-1-i];
            }
        }
    }else{
        for(i=N-1;i>=0;i--){
            for(j=0;j<N-(N-1-i);j++){
                copyArr[N-1-i][j+N-1-i]=arr[i][j+N-1-i];
            }
        }
    }
}

int doThree(int copyArr[][N],int insCheck[], int arr[][N]){
    /*
    Do the third sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
    Returns: 
        The new array
    */
    int i,j;

    if(insCheck[1]==1){
        for(i=0;i<N;i++){
            for(j=0;j<(1+i);j++){
                copyArr[i][j]=arr[i][j];
            }
        }
    }else{
        for(i=N-1;i>=0;i--){
            for(j=N-1;j>=(N-1-i);j--){
                copyArr[N-1-i][N-1-j]=arr[i][N-1-j];
            }
        }
    }
}

int doFour(int copyArr[][N],int insCheck[], int arr[][N]){
    /*
    Do the fourth sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
    Returns: 
        The new array
    */
    int i,j;

    if(insCheck[1]==1){
        for(i=0;i<N;i++){
            for(j=0;j<N-i;j++){
                copyArr[i][j+i]=arr[i][j+i];
            }
        }
    }else{
        for(i=N-1;i>=0;i--){
            for(j=i;j<N;j++){
                copyArr[N-1-i][j]=arr[i][j];
            }
        } 
    }
}

int doFive(int copyArr[][N],int insCheck[], int arr[][N]){
    /*
    Do the fifth sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
    Returns: 
        The new array
    */
    int i,j;
    
    if(insCheck[1]==1){
        for(i=0;i<N/2;i++){
            for(j=0;j<=i;j++){
                copyArr[i][j]=arr[i][j];
            }
        }
        for(i=N/2;i<N;i++){
            for(j=0;j<N-i;j++){
                copyArr[i][j]=arr[i][j];
            }
        }
    }else{
        for(i=N-1;i>N/2;i--){
            for(j=0;j<=N-1-i;j++){
                copyArr[N-1-i][j]=arr[i][j];
            }
        }
        for(i=N/2;i>=0;i--){
            for(j=0;j<=i;j++){
            copyArr[N-1-i][j]=arr[i][j];
            }
        }
    }
}

int doSix(int copyArr[][N],int insCheck[], int arr[][N]){
    /*
    Do the sixth sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
        k (int): counter
    Returns: 
        The new array
    */
    int i,j,k;

    if(insCheck[1]==1){
        for(i=0;i<=N/2;i++){
            for(j=0;j<N-2*i;j++){
                for(k=0;k<i;k++){
                    copyArr[i][k]=-1;
                }
                copyArr[i][j+k]=arr[i][j+i];
            }
        }
    }else{
        for(i=N/2;i<N;i++){
            for(j=0;j<N-2*(N-1-i);j++){
                for(k=0;k<N-1-i;k++){
                    copyArr[i][k]=-1;
                }
                copyArr[i-N/2][j+k]=arr[N-1-i][j+N-1-i];
            }
        }
    }
}

int doSeven(int copyArr[][N],int insCheck[], int arr[][N]){
    /*
    Do the seventh sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
    Returns: 
        The new array
    */
    int i,j;
    
    if(insCheck[1]==1){
        for(i=0;i<N/2;i++){
            for(j=0;j<=i;j++){
              copyArr[i][j+N-1-i]=arr[i][N-1-j];
            }
        }
        for(i=N/2;i<N;i++){
            for(j=0;j<N-i;j++){
                copyArr[i][j+i]=arr[i][j+i];
            }
        }
    }else{
        for(i=N-1;i>N/2;i--){
            for(j=0;j<N-i;j++){
              copyArr[N-1-i][j+i]=arr[i][j+i];
            }
        }
        for(i=N/2;i>=0;i--){
            for(j=0;j<=i;j++){
                copyArr[N-1-i][j+N-1-i]=arr[i][j+N-1-i];
            }
        }
    }
}

int doEight(int copyArr[][N],int insCheck[], int arr[][N]){
    /*
    Do the eighth sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        insCheck (array): The orientation
        i (int): Row
        j (int): Column
        k (int): counter
    Returns: 
        The new array
    */
    int i,j,k;

    if(insCheck[1]==1){
        for(i=N/2;i<N;i++){
            for(j=0;j<N-2*(N-1-i);j++){
                for(k=0;k<N-1-i;k++){
                    copyArr[i][k]=-1;
                }
                copyArr[i][j+k]=arr[i][j+(N-1-i)];
            }
        }
    }else{
       for(i=N-1;i>=N/2;i--){
            for(j=0;j<N-2*(N-1-i);j++){
                for(k=0;k<N-1-i;k++){
                    copyArr[i][k]=-1;
                }
                copyArr[N-1-i][j+k]=arr[i][j+N-1-i];
            }
        }
    }
}

int doNine(int copyArr[][N], int arr[][N]){
    /*
    Do the ninth sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        i (int): Row
    Returns: 
        The new array
    */
   
    int i;

    for(i=0;i<N;i++){
        copyArr[i][i]=arr[i][i];
    }
}

int doTen(int copyArr[][N], int arr[][N]){
    /*
    Do the tenth sentence
    Args:
        arr (array): Original random array
        copyArr (array): New array
        i (int): Row
    Returns: 
        The new array
    */
    int i;

    for(i=0;i<N;i++){
        copyArr[i][N-1-i]=arr[i][N-1-i];
    }
}

void printArray(int arr[][N]){
    /*
    Prints the array
    Args:
        i (int): Row
        j (int): Column
        arr (array): The random array
    Returns:
        The array
    */
    int i,j;

    printf("----------------------------------------------------\n");
    printf("      Original Table      \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("(%d,%d: %d) ",i,j,arr[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n");
}

void printResult(int copyArr[][N]){
    /*
    Prints the new array
    Args:
        i (int): Row
        j (int): Column
        copyArr (array): The new array
    Returns:
        The new array
    */
    int i,j;
    
    printf("      Final Table       \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(copyArr[i][j]==-1){
                printf("         ");
            }else{
            printf("(%d,%d: %d) ",i,j,copyArr[i][j]);
            }
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n");
}
