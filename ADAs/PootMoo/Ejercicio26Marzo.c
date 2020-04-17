/*  Author Irving Eduardo Poot Moo
    Version 1.0.0
    Program that shows a selected section of a random table NxN
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5


int genArr(int arr[][N],int auxArr[][N]);
int getIns();
int doOneandThree(int auxArr[][N], int arr[][N]);
int doTwoandFour(int auxArr[][N], int arr[][N]);
void printOriginal(int arr[][N]);
void printSection(int auxArr[][N]);
int makeDecition();
void sayGoodbye();

int main(){
    int decition, checkIns;
    decition = 1;
    while(decition==1){
        // Inputs
        int arr[N][N], auxArr[N][N];
        checkIns=getIns();
        system("clear");
        // Process
        genArr(arr,auxArr);
        if(checkIns==1){
            doTwoandFour(auxArr,arr);

        }else if(checkIns==2){
            doOneandThree(auxArr,arr);
        }

        // Outputs
        printOriginal(arr);
        printSection(auxArr);

        //Return Cycle
        decition = makeDecition();
        system("clear");
    }
    sayGoodbye();



    
    return (0);
}

int getIns(){
    /*  Ask for the section to show
    Args:
        ins (int): Ask for the section that we want
    Returns:
        The section to show
    */
   int ins=0;
   printf("******************************************\n");
   printf("    -Sections to choose-    \n");
   printf("1- Section: 2-4             \n");
   printf("2- Section: 1-3             \n");
   printf("******************************************\n");
   printf("Which section do you need?\n");
   scanf("%d",&ins);

   if(ins<1 , ins>10){
       while(ins<1 , ins>2){
           printf("Invalid Number\n");
           scanf("%d",&ins);
       }
   }
   return ins;
}

int genArr(int arr[][N], int auxArr[][N]){
    /* Generates the array
    Args:
        arr (Array): Original random array
        auxArr (Array): Modified array
        i (int): Row
        j (int): Column
    Returns:
        The Array
    */
   int i, j;
   time_t t;

   srand((unsigned) time(&t));
   for(i=0;i<N;i++){
       for(j=0;j<N;j++){
           arr[i][j]=rand()%10;
           auxArr[i][j]=-1;
       }
   }
}


int doOneandThree(int auxArr[][N], int arr[][N]){
    /* Do the requested section
    Args:
        arr (array): Original random Array
        auxArr (array): Modified Array
        checkIns (arrar): The orientation
        i (int): Row
        j (int): Column
    Retuns:
    The new array
    */

   int i, j;

    for(i=0;i<N/2;i++){
        for(j=0;j<=i;j++){
            auxArr[i][j]=arr[i][j];
        }
    }
    for(i=N/2;i<N;i++){
        for(j=0;j<N-i;j++){
            auxArr[i][j]=arr[i][j];
        }
    }
    for(i=0;i<N/2;i++){
        for(j=0;j<=i;j++){
            auxArr[i][j+N-1-i]=arr[i][N-1-j];
        }
    }
    for(i=N/2;i<N;i++){
        for(j=0;j<N-i;j++){
            auxArr[i][j+i]=arr[i][j+i];
        }
    }

   

   
}

int doTwoandFour(int auxArr[][N], int arr[][N]){
    /* Do the requested section
    Args:
        arr (array): Original random Array
        auxArr (array): Modified Array
        checkIns (arrar): The orientation
        i (int): Row
        j (int): Column
        c (int): Counter
        
    Retuns:
    The new array
    */

    int i, j, c;
    for(i=0;i<=N/2;i++){
        for(j=0;j<N-2*i;j++){
            for(c=0;c<i;c++){
                auxArr[i][c]=-1;
            }                
            auxArr[i][j+c]=arr[i][j+i];
        }
    }
    for(i=N/2;i<N;i++){
        for(j=0;j<N-2*(N-1-i);j++){
            for(c=0;c<N-1-i;c++){
                auxArr[i][c]=-1;
            }
            auxArr[i][j+c]=arr[i][j+(N-1-i)];
        }
    }
}

void printOriginal(int arr[][N]){
    /* Print the original array
    Args:
        i (int): Row
        j (int): Column
        arr (array): The random array
    Returns:
        The array
    */
   int i, j;

   printf("******************************************\n");
   printf("    -Original Array-    \n");
   for(i=0; i<N; i++){
       for(j=0;j<N;j++){
           printf("(%d,%d: %d) ",i,j,arr[i][j]);
       }
       printf("\n");
   }
   printf("******************************************\n");


}

void printSection(int auxArr[][N]){
    /* Prints the modified array
    Args:
        i (int): Row
        j (int): Column
        auxArr (Array): The new array
    Returns:
        The new Array
    */

   int i, j;

   printf("    -Section Selected-    \n");
   for(i=0;i<N;i++){
       for(j=0;j<N;j++){
           if(auxArr[i][j]==-1){
               printf("         ");
           }else{
               printf("(%d,%d: %d) ",i,j,auxArr[i][j]);
           }
       }
       printf("\n");
   }
   printf("******************************************\n");
}

int makeDecition(){
    int decition=0;
    printf("    Do you need another section?    \n");
    printf("    1)Yes  or  2)No    \n");
    scanf("%d",&decition);
    
    return decition;
}

void sayGoodbye(){
    printf("    Bye, Bye :)    ");
}
