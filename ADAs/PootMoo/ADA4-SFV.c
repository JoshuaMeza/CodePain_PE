#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int getIns();
int getIns2(int checkIns[2]);
int genArr(int arr[][N],int auxArr[][N]);

int first(int auxArr[][N],int checkIns[2],int arr[][N]);
int second(int auxArr[][N],int checkIns[2],int arr[][N]);
int third(int auxArr[][N],int checkIns[2],int arr[][N]);
int fourth(int auxArr[][N],int checkIns[2],int arr[][N]);
int fifth(int auxArr[][N],int checkIns[2],int arr[][N]);
int sixth(int auxArr[][N],int checkIns[2],int arr[][N]);
int seventh(int auxArr[][N],int checkIns[2],int arr[][N]);
int eighth(int auxArr[][N],int checkIns[2],int arr[][N]);
int nineth(int auxArr[][N],int arr[][N]);
int tenth(int auxArr[][N],int arr[][N]);
void sayGoodbye();
void printSection(int auxArr[][N]);
int makeDecition();

int main(){
    int decition;
    decition = 1;
    while(decition==1){
        // Inputs
        int arr[N][N], auxArr[N][N], checkIns[2];
        checkIns[0]=getIns();
        checkIns[1]=getIns2(checkIns);
        system("clear");
        
        // Process
        genArr(arr,auxArr);
        if(checkIns[0]==1){
        first(auxArr,checkIns,arr);
        
        }else if(checkIns[0]==2){
        second(auxArr,checkIns,arr);
        
        }else if(checkIns[0]==3){
        third(auxArr,checkIns,arr);

        }else if(checkIns[0]==4){
        fourth(auxArr,checkIns,arr);

        }else if(checkIns[0]==5){
        fifth(auxArr,checkIns,arr);

        }else if(checkIns[0]==6){
        sixth(auxArr,checkIns,arr);

        }else if(checkIns[0]==7){
        seventh(auxArr,checkIns,arr);

        }else if(checkIns[0]==8){
        eighth(auxArr,checkIns,arr);

        }else if(checkIns[0]==9){
        nineth(auxArr,arr);

        }else if(checkIns[0]==10){
        tenth(auxArr,arr);
        }

        // Outputs
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
   printf("1- Section: 1-2             \n");
   printf("2- Section: 2-3             \n");
   printf("3- Section: 3-4             \n");
   printf("4- Section: 1-4             \n");
   printf("5- First Section            \n");
   printf("6- Second Section           \n");
   printf("7- Third Section            \n");
   printf("8- Fourth Section           \n");
   printf("9- Main Diagonal            \n");
   printf("10- Inverse Diagonal        \n");
   printf("******************************************\n");
   printf("Which section do you need?\n");
   scanf("%d",&ins);

   if(ins<1 , ins>10){
       while(ins<1 , ins>10){
           printf("Invalid Number\n");
           scanf("%d",&ins);
       }
   }
   return ins;
}

int getIns2( int checkIns[]){
    /* Ask for the order
    Args:
        ins2 (int): Ask for the orientation
    Returns:
        The orientation that are we looking for
    */
   int ins2=0;

   if(checkIns[0]!=9 && checkIns[0]!=10){
       printf("****************************************************\n");
       printf("    What orientation are you looking for?    \n");
       if(checkIns[0]==1){
           printf("    1) 1-2  or  2)2-1           \n");

       }else if(checkIns[0]==2){
           printf("    1) 2-3  or  2)3-2           \n");

       }else if(checkIns[0]==3){
           printf("    1) 3-4  or  2)4-3           \n");

       }else if(checkIns[0]==4){
           printf("    1)1-4  or  2)4-1            \n");

       }else if(checkIns[0]>4){
           printf("    1)Up to down  or  2)Down to Up     \n");

       }
       printf("****************************************************\n");
       printf("1 or 2?\n");
       scanf("%d",&ins2);
       
       if(ins2<1 , ins2>2){
           while(ins2<1 , ins2>2){
               printf("Invalid Number\n");
               scanf("%d",&ins2);
           }
       }
   }
   return ins2;
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

int first(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the first order
    Args:
        arr (Array): Original random array
        auxArr (Array): Modified Array
        checkIns (Array): The orientation
        i (int): Row
        j (int): Column
    Returns:
        The new array
    */
   int i, j;
   if(checkIns[1]==1){
       for(i=0;i<N;i++){
           for(j=0;j<(N-i);j++){
               auxArr[i][j]=arr[i][j];
           }
       }
   }else{
       for(i=N-1;i>=0;i--){
           for(j=(N-1-(N-i));j>=0;j--){
               auxArr[i][j]=arr[N-1-i][j];
           }
       }
   }
}

int second(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the second order
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

   if(checkIns[1]==1){
       for(i=0;i<N;i++){
           for(j=0;j<(1+i);j++){
               auxArr[i][j]=arr[i][N-1+j-i];
           }
       }
   }else{
       for(i=(N-1);i>=0;i--){
           for(j=N-1;j>=(0+(N-1-i));j--){
               auxArr[N-1-i][N-1-j]=arr[i][N-1-j+(N-1-i)];
           }
       }
   }
}

int third(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the third order
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

   if(checkIns[1]==1){
       for(i=0;i<N;i++){
           for(j=0;j<(1+i);j++){
               auxArr[i][j]=arr[i][j];
           }
       }
   }else{
       for(i=N;i>=0;i--){
           for(j=N-1;j>=(N-1-i);j--){
               auxArr[N-1-i][N-1-j]=arr[i][N-1-j];
           }
       }
   }
}

int fourth(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the fourth order
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

   if(checkIns[i]==1){
       for(i=0;i<N;i++){
           for(j=0;j<(N-i);j++){
               auxArr[i][j]=arr[i][j+1];
           }
       }
   }else{
       for(i=N-1;i>=0;i--){
           for(j=N-1;j>=(N-1-(N-1-i));j--){
               auxArr[N-1-i][N-1-j]=arr[i][(N-1-j)+i];
           }
       }
   }
}

int fifth(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the fifth order
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

   if(checkIns[1]==2){
       for(i=0;i<N;i++){
           for(j=0;j<N;j++){
               auxArr[i][j]=arr[i][j];
           }
       }
       for(i=0;i<N;i++){
           for(j=1;j<(N-i);j++){
               auxArr[i][j+i]=-1;
               auxArr[N-1-i][j+i]=-1;
           }
       }
   }else{
       for(i=0;i<N;i++){
           for(j=0;j<N;j++){
               auxArr[N-1-i][j]=arr[i][j];
           }
       }
       for(i=0;i<N;i++){
           for(j=1;j<(N-i);j++){
               auxArr[i][j+i]=-1;
               auxArr[N-1-i][j+i]=-1;
           }
       }
   }
}

int sixth(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the sixth order
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
   if(checkIns[1]==1){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                auxArr[i][j]=arr[i][j];
            }
        }
        for(i=0;i<N;i++){
            for(j=0;j<i;j++){
                auxArr[i][j]=-1;
                auxArr[i][N-1-j]=-1;
            }
        }
    }else{
        int n=N;
        if(n%2!=0){
            n--;
        }

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                auxArr[i][j]=arr[i][j];
            }
        }
        for(i=0;i<N;i++){
            for(j=0;j<i;j++){
                auxArr[i][j]=-1;
                auxArr[i][N-1-j]=-1;
            }
        }
        for(i=0;i<(n/2);i++){
            for(j=0;j<N;j++){
                auxArr[N-1-i][j]=auxArr[i][j];
                auxArr[i][j]=-1;
            }
        }
        for(i=0;i<((n/2)+1);i++){
            for(j=0;j<N;j++){
                auxArr[i][j]=auxArr[i+(n/2)][j];
                auxArr[i+(n/2)][j]=-1;
            }
        }
    }
   
}

int seventh(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the seventh order
    Args:
        arr (array): Original random Array
        auxArr (array): Modified Array
        checkIns (arrar): The orientation
        i (int): Row
        j (int): Column
    Retuns:
        The new array
    */
   int i,j,n=N;
    if(n%2!=0){
        n++;
    }
    
    if(checkIns[1]==1){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
              auxArr[i][j]=arr[i][j];
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<1+i;j++){
                auxArr[i][j]=auxArr[i][j+N-1-i];
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<1+i;j++){
                auxArr[n/2+i][j]=auxArr[n/2+i][j+n/2];
            }
        }
        for(i=0;i<N;i++){
            for(j=1;j<(N-i);j++){
                auxArr[i][j+i]=-1;
                auxArr[N-1-i][j+i]=-1;
            }
        }
    }else{
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
              auxArr[N-1-i][j]=arr[i][j];
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<1+i;j++){
                auxArr[i][j]=auxArr[i][j+N-1-i];
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<1+i;j++){
                auxArr[n/2+i][j]=auxArr[n/2+i][j+n/2];
            }
        }
        for(i=0;i<N;i++){
            for(j=1;j<(N-i);j++){
                auxArr[i][j+i]=-1;
                auxArr[N-1-i][j+i]=-1;
            }
        }
    }
}

int eighth(int auxArr[][N], int checkIns[], int arr[][N]){
    /* Do the eighth order
    Args:
        arr (array): Original random Array
        auxArr (array): Modified Array
        checkIns (arrar): The orientation
        i (int): Row
        j (int): Column
    Retuns:
        The new array
    */
   int i,j;

    if(checkIns[1]==1){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                auxArr[i][j]=arr[i][j];
            }
        }
        for(i=0;i<N;i++){
            for(j=0;j<(N-i-1);j++){
                auxArr[i][j+i+1]=-1;
                auxArr[i][N-1-j-i-1]=-1;
            }
        }
    }else{
        int n=N;
        if(n%2!=0){
            n--;
        }

       for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                auxArr[i][j]=arr[i][j];
            }
        }
        for(i=0;i<(N-1);i++){
            for(j=0;j<(N-1-i);j++){
                auxArr[i][j+i+1]=-1;
                auxArr[i][N-1-j-i-1]=-1;
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<N;j++){
                auxArr[i][j]=auxArr[N-1-i][j];
                auxArr[N-1-i][j]=-1;
            }
        }
    }
}

int nineth(int auxArr[][N], int arr[][N]){
    /* Do the nineth order
    Args:
        arr (array): Original random Array
        auxArr (array): Modified Array
        checkIns (arrar): The orientation
        i (int): Row
        j (int): Column
    Retuns:
        The new array
    */
   int i, j=0;

   for(i=0;i<N;i++){
       auxArr[i][j]=arr[i][i];
   }
}

int tenth(int auxArr[][N], int arr[][N]){
    /* Do the tenth order
    Args:
        arr (array): Original random Array
        auxArr (array): Modified Array
        checkIns (arrar): The orientation
        i (int): Row
        j (int): Column
    Retuns:
        The new array
    */

   int i, j=0;

   for (i=0;i<N;i++){
       auxArr[i][j]=arr[i][N-1-i];
   }
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
           if(auxArr[i][j]!=-1){
               printf("(%d,%d: %d) \n",i,j,auxArr[i][j]);
           }
           
       }
       
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