/*
    Author Joshua Immanuel Meza Magaña
    Version 1.0.0
    Date 07/04/2020
    Program who saves total amounts of money per day 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define ch 121

typedef struct date{
    int dd;
    int mm;
    int yyyy;
    int total;
}DATE;
typedef struct info{
    char name[ch];
    float money;
    DATE date;
}INFO;
typedef struct node{
    INFO data;
    struct node *nextNode;
}NODE;
typedef NODE *NodePTR; /* Node Pointer */

int displayMenu();
void deleteNode(NodePTR *,int *);
void asigStr(char name[ch]);
void askContinue(int *);
void getDate(int *,int *,int *,int *);
float getMoney();
void insertOrganized(NodePTR *,char*,float,int,int,int,int);
void printList(NodePTR);

int main(){
    /* Input */
    NodePTR headPTR=NULL;
    int flag=1,i=0,dd,mm,yyyy,total,option=0,sec1=0,sec2=0,lists=0;
    char name[ch];
    float money;

    /* Process */

    while(option!=2){
        option=displayMenu();
        if(option==0){
            sec1=1;
            sec2=1;
            while(flag==1){
                lists+=1;
                fflush(stdin);
                asigStr(name);
                getDate(&dd,&mm,&yyyy,&total);
                money=getMoney();

                insertOrganized(&headPTR,name,money,dd,mm,yyyy,total);

                askContinue(&flag);
            } 
        }else if(option==1){
            if(sec1==0){
                printf("Sorry, but you can't delete a list if you haven't created one yet.\n");
                option=0;
            }else if(lists==0){
                printf("Sorry, but you can't delete a list if you don't have anyone.\n");
                option=0;
            }else if(lists==1){
                printf("Sorry, but you can't delete your unique list.\n");
                option=0;
            }else{
                deleteNode(&headPTR,&lists);
                lists-=1; 
            }
        }else{
            if(sec2==0){
                printf("Sorry, but you can't print a list if you haven't created one yet.\n");
                option=0;
            }else if(lists==0){
                printf("Sorry, but you can't print a list if you don't have anyone.\n");
                option=0;
            }
        }
    }

    /* Output */
    printList(headPTR);

    return 0;
}

/* Functions */

int displayMenu(){
    /*
    Displays the menu
    Args:
        selected (int): selection of the user
    Returns:
        The instruction of the user
    */
    int selected;

    printf("-----------\n");
    printf("Menu\n");
    printf("-----------\n");
    printf("(1) Add a list\n");
    printf("(2) Erase a list\n");
    printf("(3) Print the lists\n");
    printf("-----------\n");
    printf("Enter your selection: ");
    scanf("%d",&selected);
    printf("\n-----------\n");

    selected-=1;

    if(selected<0 || selected>2){
        while(selected<0 || selected>2){
            printf("Error, try again: ");
            scanf("%d",&selected);
        }
    }

    return selected;
}

void deleteNode(NodePTR *nptr,int *list){
    /*
    It delete a node
    Args:
        nptr (NodePtr): pointer to the header
        _dd (int): day
        _mm (int): month
        _yyyy (int): year
        _total (int): standard value of date
    Returns
        The list without the selected node
    */
    int _dd,_mm,_yyyy,_total;
    NodePTR temp, actualNode=*nptr;

    printf("To delete a list, I will need the date.\n");
    printf("First, insert the year (yyyy): ");
    scanf("%d",&_yyyy);
    printf("Second, insert the month (mm): ");
    scanf("%d",&_mm);
    printf("Third, insert the day (dd): ");
    scanf("%d",&_dd);

    _total=_yyyy*10000+_mm*100+_dd;
    
    if(actualNode -> data.date.total==_total){
        temp=actualNode;
        *nptr=actualNode->nextNode;
        temp -> nextNode=NULL;
        free(temp);
    }else{
        while(actualNode -> data.date.total!=_total){
            if(actualNode -> nextNode==NULL){
                printf("-----------\n");
                printf("This date does not exist.\n");
                *list+=1;
                break;
            }
            temp=actualNode;
            actualNode=actualNode -> nextNode;
        }
        if(actualNode -> data.date.total==_total){
            if(actualNode -> nextNode==NULL){
                actualNode=temp;
                temp=actualNode -> nextNode;
                actualNode -> nextNode=NULL;
                free(temp);
            }else{
                actualNode=temp;
                temp=actualNode -> nextNode;
                actualNode -> nextNode=temp -> nextNode;
                free(temp);
            }
        }
    }
}

void asigStr(char name[ch]){
    /*
    Get the name
    Args:
        a (char): temporary string
        name (char): dinamic memory for the string
    Returns:
        The name with the correct space of memory
    */
    printf("Insert the name of the person who used the cash register that day: ");
    gets(name);
}

void askContinue(int *flag){
    /*
    Check if the user wants to register another day
    Args:
        a (int): saves a char
    Returns:
        The decision
    */
    char a;

    printf("Do you want to register another day? (Y/N)\nR: ");
    scanf(" %c",&a);
    a=toupper(a);
    
    if(a!='Y' && a!='N'){
        while(a!='Y' && a!='N'){
            printf("Incorrect option, try again: ");
            scanf(" %c",&a);
            a=toupper(a);
        }
    }

    if(a=='Y'){
        *flag=1;
    }else{
        *flag=0;
    }
}

void getDate(int *dd,int *mm,int *yyyy,int *total){
    /*
    Obtains the correct date
    Args:
        dd (int): days
        mm (int): months
        yyyy (int): years
        ly (int): leap year
        final (int): final date
    Returns:
        The date
    */
    int ly=0;

    printf("Insert the year (yyyy): ");
    scanf("%d",yyyy);
    if(*yyyy%4==0){
        ly=1;
    }
    printf("Insert the month (mm): ");
    scanf("%d",mm);
    while(*mm<1 || *mm>12){
        printf("Select a month between 1 and 12: ");
        scanf("%d",mm);
    }
    printf("Insert the day (dd): ");
    scanf("%d",dd);
    if(*mm<=6){
        if(*mm%2!=0){
            if(*dd<0 || *dd>31){
                while(*dd<0 || *dd>31){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",dd);
                }
            }
        }else if(*mm==2){
            if(ly==1){
                if(*dd<0 || *dd>29){
                while(*dd<0 || *dd>29){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",dd);
                }
            }
            }else{
                if(*dd<0 || *dd>28){
                while(*dd<0 || *dd>28){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",dd);
                }
            }
            }
        }else{
            if(*dd<0 || *dd>30){
                while(*dd<0 || *dd>30){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",dd);
                }
            }
        }
    }else{
        if(*mm==9 || *mm==11){
            if(*dd<0 || *dd>30){
                while(*dd<0 || *dd>30){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",dd);
                }
            }
        }else{
            if(*dd<0 || *dd>31){
                while(*dd<0 || *dd>31){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",dd);
                }
            }
        }
    }
    *total=(*yyyy)*10000+(*mm)*100+(*dd);
}

float getMoney(){
    /*
    It reads the amount of money
    Args:
        money (float): Amount of money
    Returns:
        The amount of money
    */
   float _money;

   printf("Insert the amount of money: ");
   scanf("%f",&_money);

   return _money;
}

void insertOrganized(NodePTR *nptr,char* _name,float _money,int _dd,int _mm,int _yyyy,int _total){
    /*
    Isert the new node
    Args:
        newNode (NodePTR): New node 
        actualNode (NodePTR): Node to the header
        previousNode (NodePTR): References to the previous node
        _name (char): string of the name
        _money (float): value of the money
        _dd (int): day
        _mm (int): month
        _yyyy (int): year
        _total (int): standard value of the day
    Returns:
        The new node organized
    */
    NodePTR newNode, actualNode=*nptr, previousNode=NULL;

    newNode=(NODE*)malloc(sizeof(NODE)); 
    
    if(newNode!=NULL){
        strcpy(newNode -> data.name,_name);
        newNode -> data.date.dd=_dd;
        newNode -> data.date.mm=_mm;
        newNode -> data.date.yyyy=_yyyy;
        newNode -> data.date.total=_total;
        newNode -> data.money=_money;
        newNode -> nextNode=NULL;

        while(actualNode!=NULL && _total>actualNode->data.date.total){
            previousNode=actualNode;
            actualNode=actualNode->nextNode;
        }

        if(previousNode==NULL){
            newNode -> nextNode=*nptr;
            *nptr=newNode;
        }else{
            previousNode -> nextNode=newNode;
            newNode -> nextNode=actualNode;
        }
    }else{
        printf("There is no more memory\n");
    }
}

void printList(NodePTR actualNode){
    /*
    Print the list
    Args:
        actualNode (NodePTR): Pointer of the first node
    */
    if(actualNode==NULL){
        printf("-----------\n");
        printf("Empty list");
        printf("-----------\n");
    }else{
        printf("-----------\n");
        printf("List:\n");

        while(actualNode!=NULL){
            printf("-----------\n");
            printf("Name: %s\n",actualNode->data.name);
            printf("Date: %d/%d/%d\n",actualNode->data.date.dd,actualNode->data.date.mm,actualNode->data.date.yyyy);
            printf("Money: %.2f\n",actualNode->data.money);

            actualNode=actualNode->nextNode;
        }
        printf("-----------\n");
    }
}
