/*
    Author Joshua Immanuel Meza Magaña
    Version 1.0.1
    Date 30/03/2020
    Program who makes operations with two rational numbers
*/
#include <stdio.h>
#include <math.h>

struct rational{
    int num;
    int den;
};

void readNum(struct rational *,struct rational *,int);
void readDen(struct rational *,struct rational *,int);
void addRational(struct rational,struct rational,struct rational *);
void subRational(struct rational,struct rational,struct rational *);
void mulRational(struct rational,struct rational,struct rational *);
void divRational(struct rational,struct rational,struct rational *);
void simpRational(struct rational *);
void printRes(struct rational,struct rational,struct rational,struct rational);

int main(){
    /* Input */
    struct rational r1, r2, res1, res2, res3, res4;
    int res[4][2],insFlag=0;
    while(insFlag<=1){
        readNum(&r1,&r2,insFlag);
        readDen(&r1,&r2,insFlag); 
        insFlag++;   
    }

    /* Process */
    addRational(r1,r2,&res1);
    subRational(r1,r2,&res2);
    mulRational(r1,r2,&res3);
    divRational(r1,r2,&res4);

    /* Output */
    printRes(res1,res2,res3,res4);

    return 0;
}

/* Functions */

void readNum(struct rational *r1,struct rational *r2, int insFlag){
    /*
    It reads the numerators
    Args:
        r1 (structure): First rational
        r2 (structure): Second rational
        insFlag (int): Flag to know which rational is 
    Returns:
        The numerators
    */
    if(insFlag==0){
        printf("Insert the first numerator: ");
        scanf("%d",&r1 -> num);
    }else{
        printf("Insert the second numerator: ");
        scanf("%d",&r2 -> num);
    }
}

void readDen(struct rational *r1,struct rational *r2, int insFlag){
    /*
    It reads the numerators
    Args:
        r1 (structure): First rational
        r2 (structure): Second rational
        insFlag (int): Flag to know which rational is 
    Returns:
        The numerators
    */
    if(insFlag==0){
        printf("Insert the first denominator: ");
        scanf("%d",&r1 -> den);
        while(r1 -> den ==0){
            printf("ERROR, TRY AGAIN: ");
            scanf("%d",&r1 -> den);
        }
    }else{
        printf("Insert the second numerator: ");
        scanf("%d",&r2 -> den);
         while(r2 -> den ==0){
            printf("ERROR, TRY AGAIN: ");
            scanf("%d",&r2 -> den);
        }
    }
}

void addRational(struct rational r1,struct rational r2,struct rational *res1){
    /*
    Do the sum of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The sum of fractions 
    */
    res1 -> num=r1.num*r2.den+r1.den*r2.num;
    res1 -> den=r1.den*r2.den;

    simpRational(res1);
}

void subRational(struct rational r1,struct rational r2,struct rational *res2){
    /*
    Do the substraction of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The substraction of fractions 
    */
    res2 -> num=r1.num*r2.den-r1.den*r2.num;
    res2 -> den=r1.den*r2.den;

    simpRational(res2);
}

void mulRational(struct rational r1,struct rational r2,struct rational *res3){
    /*
    Do the multiplication of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The multiplication of fractions 
    */
    res3 -> num=r1.num*r2.num;
    res3 -> den=r1.den*r2.den;

    simpRational(res3);
}

void divRational(struct rational r1,struct rational r2,struct rational *res4){
    /*
    Do the division of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The division of fractions 
    */
    res4 -> num=r1.num*r2.den;
    res4 -> den=r1.den*r2.num;

    simpRational(res4);
}

void simpRational(struct rational *res){
    /*
    It simplifies the result
    Args:
        res (array): contains the results of the operations
        position (int): describes which operation is simplifying
        N (int): spaces for the array
        prime (array): list of prime numbers in the domain
        i (int): counter
        j (int): counter
    Returns:
        The final result
    */
    int N,i,j;

    /* Length of the array of prime numbers */
    if(res -> num > res -> den){
        N=res -> num;
    }else{
        N=res -> den;
    }

    if(N<0){
        N*=-1;
    }

    int prime[N];
    
    /* Sieve of Eratosthenes */
    for(i=0;i<N;i++){
        prime[i]=i+2;
    }
    
    for(i=0;i<sqrt(N);i++){
        if(prime[i]!=0){
            j=i+1;
            while(j<N){
                if(prime[j]%prime[i]==0){
                    prime[j]=0;
                }
                j++;
            }
        }
    }

    /* Reduction */
    i=0;
    while(i<N){
        if(prime[i]==0){
            i++;
        }else{
            if((res -> num)%prime[i]==0 && (res -> den)%prime[i]==0){
                res -> num/=prime[i];
                res -> den/=prime[i];
            }else{
            i++;
            }
        }
    }
}

void printRes(struct rational res1,struct rational res2,struct rational res3,struct rational res4){
    /* Print the results */
    if(res1.den==0){
        printf("Sum of fractions: Undefined\n");
    }else if(res1.num==res1.den){
        printf("Sum of fractions: 1\n");
    }else if(res1.den==1){
        printf("Sum of fractions: %d\n",res1.den);
    }else if(res1.den==-1){
        printf("Sum of fractions: %d\n",res1.den*-1);
    }else if(res1.num==0){
        printf("Sum of fractions: 0\n");
    }else if(res1.num<0 && res1.den<0){
        printf("Sum of fractions: %d/%d\n",res1.num*-1,res1.den*-1);
    }else if(res1.num<0 || res1.den<0){
        if(res1.num<0){
            printf("Sum of fractions: %d/%d\n",res1.num,res1.den);
        }else{
            printf("Sum of fractions: -%d/%d\n",res1.num,res1.den*-1);
        }
    }else{
        printf("Sum of fractions: %d/%d\n",res1.num,res1.den);
    }

    if(res2.den==0){
        printf("Substraction of fractions: Undefined\n");
    }else if(res2.num==res2.den){
        printf("Substraction of fractions: 1\n");
    }else if(res2.den==1){
        printf("Substraction of fractions: %d\n",res2.den);
    }else if(res2.den==-1){
        printf("Substraction of fractions: %d\n",res2.den*-1);
    }else if(res2.den==0){
        printf("Substraction of fractions: 0\n");
    }else if(res2.num<0 && res2.den<0){
        printf("Substraction of fractions: %d/%d\n",res2.num*-1,res2.den*-1);
    }else if(res2.num<0 || res2.den<0){
        if(res2.num<0){
            printf("Substraction of fractions: %d/%d\n",res2.num,res2.den);
        }else{
            printf("Substraction of fractions: -%d/%d\n",res2.num,res2.den*-1);
        }
    }else{
        printf("Substraction of fractions: %d/%d\n",res2.num,res2.den);  
    }
    
    if(res3.den==0){
        printf("Multiplication of fractions: Undefined\n");
    }else if(res3.num==res3.den){
        printf("Multiplication of fractions: 1\n");
    }else if(res3.den==1){
        printf("Multiplication of fractions: %d\n",res3.num);
    }else if(res3.den==-1){
        printf("Multiplication of fractions: %d\n",res3.num*-1);
    }else if(res3.num==0){
        printf("Multiplication of fractions: 0\n");
    }else if(res3.num<0 && res3.den<0){
        printf("Multiplication of fractions: %d/%d\n",res3.num*-1,res3.den*-1);
    }else if(res3.num<0 || res3.den<0){
         if(res3.num<0){
            printf("Multiplication of fractions: %d/%d\n",res3.num,res3.den);
        }else{
            printf("Multiplication of fractions: -%d/%d\n",res3.num,res3.den*-1);
        }
    }else{
        printf("Multiplication of fractions: %d/%d\n",res3.num,res3.den);  
    }
    
    if(res4.den==0){
        printf("Division of fractions: Undefined");
    }else if(res4.num==res4.den){
        printf("Division of fractions: 1\n");
    }else if(res4.den==1){
        printf("Division of fractions: %d\n",res4.num);
    }else if(res4.den==-1){
        printf("Division of fractions: %d\n",res4.num*-1);
    }else if(res4.num==0){
        printf("Division of fractions: 0\n");
    }else if(res4.num <0 && res4.den<0){
        printf("Division of fractions: %d/%d\n",res4.num*-1,res4.den*-1);
    }else if(res4.num<0 || res4.den<0){
         if(res4.num<0){
            printf("Division of fractions: %d/%d\n",res4.num,res4.den);
        }else{
            printf("Division of fractions: -%d/%d\n",res4.num,res4.den*-1);
        }
    }else{
        printf("Division of fractions: %d/%d\n",res4.num,res4.den);  
    }  
}
