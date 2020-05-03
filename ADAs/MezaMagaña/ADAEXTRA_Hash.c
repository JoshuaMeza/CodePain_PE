/*
Author Joshua Immanuel Meza Magaña
Date 30/04/2020
Version 1.0.0
Program who saves the worker's name, the amount of money and the date 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#define minYear 2020
#define maxLen 151

typedef char* STRING;
typedef struct date{
    int dd;
    int mm;
    int yyyy;
}DATE;
typedef struct info{
    STRING name;
    float money;
    int dateCode; //Key
    DATE *day;
}INFO;

int displayMenu();
void asigStr(STRING *);
void getDate(int *,int *,int *,int *);
void askDay(int *,int,int);
void askMonth(int *,int);
void askYear(int *);
void getMoney(float *);
void expandArray(int,INFO **,int *);
void addData(INFO **,STRING,float,int,int,int,int,int *);
void askContinue(int *);
void deleteSave(INFO **,int *);
void searchSpecific(INFO *);
void printContainers(INFO *,int);
void printSpecific(INFO *,int);

int main(){
    /* Input */
    INFO *hashArray;
    STRING name;
    int flag,dd,mm,yyyy,dateCode,option=0,secure=0,lists=0,top=0;
    float money;

    /* Process */
    while(option!=3){
        option=displayMenu();
        if(option==0){
            flag=1;
            secure=1;
            while(flag==1){
                lists+=1;
                fflush(stdin);
                asigStr(&name);
                getDate(&dd,&mm,&yyyy,&dateCode);
                getMoney(&money);

                expandArray(dateCode,&hashArray,&top);
                
                addData(&hashArray,name,money,dateCode,dd,mm,yyyy,&lists);
                printf("\n%s\n\n",hashArray[dateCode-1-minYear*10000].name);

                askContinue(&flag);
            } 
        }else if(option==1){
            if(secure==0 || lists==0){
                printf("Sorry, but you can't delete a save if you don't have anyone.\n");
            }else{
                deleteSave(&hashArray,&lists);
                lists-=1;
            }
        }else if(option==2){
            if(secure==0 || lists==0){
                printf("Sorry, but you can't search a save if you haven't created one yet.\n");
            }else{
                searchSpecific(hashArray);
            }
        }else if(option==3){
            if(secure==0 || lists==0){
                printf("Sorry, but you can't print a list if you haven't created one yet.\n");
                option=0;
            }
        }
    }

    /* Output */
    printContainers(hashArray,top);

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
    printf("(1) Add a save\n");
    printf("(2) Erase a save\n");
    printf("(3) Search a specific save\n");
    printf("(4) Print all the saves\n");
    printf("-----------\n");
    printf("Enter your selection: ");
    scanf("%d",&selected);
    printf("-----------\n");

    selected-=1;

    if(selected<0 || selected>3){
        while(selected<0 || selected>3){
            printf("Error, try again: ");
            scanf("%d",&selected);
            selected-=1;
        }
    }

    return selected;
}

void asigStr(STRING *name){
    /*
    Get the name
    Args:
        a (char): temporary string
        name (char): dinamic memory for the string
    Returns:
        The name with the correct space of memory
    */
    char temp[maxLen];
    int length;

    printf("Insert the name of the person who used the cash register that day: ");
    gets(temp);

    length=strlen(temp);

    *name=(STRING)malloc((length+1)*sizeof(char));

    strcpy(*name,temp);
}

void getDate(int *dd,int *mm,int *yyyy,int *dateCode){
    /*
    Obtains the correct date
    Args:
        dd (int): days
        mm (int): months
        yyyy (int): years
        dateCode (int): code for date
    Returns:
        The date and their code, neccesary for the key
    */

    askYear(yyyy);

    askMonth(mm, *yyyy);

    askDay(dd, *mm, *yyyy);

    *dateCode=(*yyyy)*10000+(*mm)*100+(*dd);
}

void askDay(int *day, int month, int year){
    /*
    Ask the day
    Args:
        day (int): Day
        year (int): Year
        month (int): Month
        ly (int): flag to leap year
        varDay (int): Actual day
        varMonth (int): Actual month
        varYear (int): Actual year
        cond (int): A condition for actual years
    Returns:
        The day
    */
    int varDay,varMonth,varYear,cond=0,ly=0;
    time_t now;

    time(&now);

    struct tm *local = localtime(&now);

    varMonth=local -> tm_mon + 1;
    varYear=local -> tm_year + 1900;
    varDay=local -> tm_mday;

    if(year%4==0){
        ly=1;
    }

    printf("Insert the day (dd): ");
    scanf("%d",day);

    while(cond==0){
        cond=1;
        if(year<varYear){
            if(month<=6){
                if(month%2!=0){
                    if(*day<0 || *day>31){
                        printf("The day is incorrect, try again: ");
                        scanf("%d",day);
                        cond=0;
                    }
                }else if(month==2){
                    if(ly==1){
                        if(*day<0 || *day>29){
                            printf("The day is incorrect, try again: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }else{
                        if(*day<0 || *day>28){
                            printf("The day is incorrect, try again: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }
                }else{
                    if(*day<0 || *day>30){
                        printf("The day is incorrect, try again: ");
                        scanf("%d",day);
                        cond=0;
                    }
                }
            }else{
                if(month==9 || month==11){
                    if(*day<0 || *day>30){
                        printf("The day is incorrect, try again: ");
                        scanf("%d",day);
                        cond=0;
                    }
                }else{
                    if(*day<0 || *day>31){
                        printf("The day is incorrect, try again: ");
                        scanf("%d",day);
                        cond=0;
                    }
                }
            }
        }else{
            if(month>varMonth){
                printf("Please, insert a valid day: ");
                scanf("%d",day);
                cond=0;
            }else if(month==varMonth){
                if(month<=6){
                    if(month%2!=0){
                        if(*day<0 || *day>31 || *day>varDay){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }else if(month==2){
                        if(ly==1){
                            if(*day<0 || *day>29 || *day>varDay){
                                printf("Please, insert a valid day: ");
                                scanf("%d",day);
                                cond=0;
                            }
                        }else{
                            if(*day<0 || *day>28 || *day>varDay){
                                printf("Please, insert a valid day: ");
                                scanf("%d",day);
                                cond=0;
                            }
                        }
                    }else{
                        if(*day<0 || *day>30 || *day>varDay){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }
                }else{
                    if(month==9 || month==11 || *day>varDay){
                        if(*day<0 || *day>30){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }else{
                        if(*day<0 || *day>31 || *day>varDay){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }
                }
            }else{
                if(month<=6){
                    if(month%2!=0){
                        if(*day<0 || *day>31){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }else if(month==2){
                        if(ly==1){
                            if(*day<0 || *day>29){
                                printf("Please, insert a valid day: ");
                                scanf("%d",day);
                                cond=0;
                            }
                        }else{
                            if(*day<0 || *day>28){
                                printf("Please, insert a valid day: ");
                                scanf("%d",day);
                                cond=0;
                            }
                        }
                    }else{
                        if(*day<0 || *day>30){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }
                }else{
                    if(month==9 || month==11){
                        if(*day<0 || *day>30){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }else{
                        if(*day<0 || *day>31){
                            printf("Please, insert a valid day: ");
                            scanf("%d",day);
                            cond=0;
                        }
                    }
                }
            }
        }
    }
}

void askMonth(int *month, int year){
    /*
    Ask the month
    Args:
        year (int): Year
        month (int): Month
        varMonth (int): Actual month
        varYear (int): Actual year
        cond (int): A condition for actual years
    Returns:
        The month
    */
    int varMonth,varYear,cond=0;
    time_t now;

    time(&now);

    struct tm *local = localtime(&now);

    varMonth=local -> tm_mon + 1;
    varYear=local -> tm_year + 1900;

    printf("Insert the month (mm): ");
    scanf("%d",month);

    while(cond==0){
        cond=1;

        if(year<varYear){
            if(*month<1 || *month>12){
                printf("Please insert a month between 1 and 12: ");
                scanf("%d",month);
                cond=0;
            }
        }else if(*month>varMonth){
            printf("Please insert a valid month: ");
            scanf("%d",month);
            cond=0;
        }
    }
}

void askYear(int *year){
    /*
    Ask the year, limited by a minimal year
    Args:
        year (int): Year
        varYear (int): Actual year
    Returns: 
        The year
    */
    int varYear;
    time_t now;

    time(&now);

    struct tm *local = localtime(&now);

    varYear=local -> tm_year + 1900;

    printf("Insert the year (yyyy): ");
    scanf("%d",year);
    
    while(*year<minYear || *year>varYear){
        if(*year<minYear){
            printf("Please insert a year equal or bigger than %d: ",minYear);
            scanf("%d",year);
        }
        if(*year>varYear){
            printf("Please insert a valid year: ");
            scanf("%d",year);
        }
    }
}

void getMoney(float *money){
    /*
    It reads the amount of money
    Args:
        money (float): Amount of money
    Returns:
        The amount of money
    */
   printf("Insert the amount of money: ");
   scanf("%f",money);
}

void expandArray(int dateCode,INFO **hashArray,int *top){
    /*
    Give memory to the array
    Args:
        dateCode (int): Code for the date
        hashArray (INFO): Contains pointers to the structs
        rows (int): Index value interpreted as rows amount
        top (int): Pointer to a flag, determinates if the table need more memory
        i (int): Counter
    */
    int rows=(dateCode-(minYear*10000)),i;

    if (*top==0){
        *hashArray=(INFO*)malloc((rows)*sizeof(INFO));

        for(i=0;i<rows;i++){
            (*hashArray)[i].dateCode=-1;
            
            (*hashArray)[i].day=(DATE*)malloc(sizeof(DATE));
        }

        *top=rows;
    }else if(rows>*top){
        *hashArray=(INFO*)realloc((*hashArray),((rows-(*top))*sizeof(INFO)));

        for(i=*top;i<rows;i++){
            (*hashArray)[i].dateCode=-1;
            
            (*hashArray)[i].day=(DATE*)malloc(sizeof(DATE));
        }

        *top=rows;
    }
}

void addData(INFO **hashArray,STRING _name,float _money,int _dateCode,int day,int month, int year,int *lists){
    /*
    Add the information
    Args:
        hashArray (INFO): Contains pointers to the structs
        index (int): Value of the position of the save
        name (STRING): Contains the worker's name
        money (float): Amount of money
        dateCode (int): code for date
        day (int): Day
        year (int): Year
        month (int): Month
    Returns:
        Nothing
    */
    int index=(_dateCode-(minYear*10000)-1),length;
    
    if((*hashArray)[index].dateCode==-1){
        length=strlen(_name);
        (*hashArray)[index].name=(STRING)malloc((length+1)*sizeof(char));
        strcpy((*hashArray)[index].name,_name);

        (*hashArray)[index].money=_money;

        (*hashArray)[index].dateCode=_dateCode;

        (*hashArray)[index].day -> dd=day;
        (*hashArray)[index].day -> mm=month;
        (*hashArray)[index].day -> yyyy=year;
        printf("-----------\n");
        printf("Succesfully Assignated\n");
        printf("-----------\n");
    }else{
        printf("-----------\n");
        printf("Assignation error, this date already exist\n");
        printf("-----------\n");
        *lists-=1;
    }
}

void askContinue(int *flag){
    /*
    Check if the user wants to register another day
    Args:
        flag (int): flag
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

void deleteSave(INFO **harshArray,int *lists){
    /*
    Delete the secure key of the save
    Args:
        hashArray (INFO): Contains pointers to the structs
        day (int): Day
        year (int): Year
        month (int): Month
        key (int): Code of date 
        index (int): Value to find the position of the save
    Returns:
        Nothing
    */
    int day,month,year,key,index;

    printf("To delete a save, you need to insert the date:\n");
    getDate(&day,&month,&year,&key);

    index=(key-(minYear*10000)-1);

    if((*harshArray)[index].dateCode==-1){
        *lists+=1;

        printf("-----------\n");
        printf("Nothing Deleted\n");
    }else{
        (*harshArray)[index].dateCode=-1;

        printf("-----------\n");
        printf("Succesfully Deleted\n");
    }
}

void searchSpecific(INFO *harshArray){
    /*
    Search and print a specific save
    Args:
        hashArray (INFO): Contains pointers to the structs
        day (int): Day
        year (int): Year
        month (int): Month
        key (int): Code of date 
        index (int): Value to find the position of the save
    Returns:
        Nothing
    */
    int day,month,year,key,index;

    printf("To search a save, you need to insert the date:\n");
    getDate(&day,&month,&year,&key);

    index=(key-(minYear*10000)-1);

    printSpecific(harshArray,index);
}

void printContainers(INFO *hashArray,int top){
    /*
    Print all the containers
    Args:
        hashArray (INFO): contains pointers to the structs
        i (int): counter
    Returns: 
        Nothing
    */
    int i;
    
    printf("List:\n");

    for(i=0;i<top;i++){
        if(hashArray[i].dateCode!=-1){
            printSpecific(hashArray,i);
        }
    }
    printf("-----------\n");
}

void printSpecific(INFO *hashArray,int i){
    /*
    Print specific information
    Args:
        hashArray (INFO): contains pointers to the structs
    Returns:
        Nothing
    */
    if(hashArray[i].dateCode==-1){
        printf("-----------\n");
        printf("There's no results.\n");
    }else{
        printf("-----------\n");
        printf("Name: %s\n",hashArray[i].name);
        printf("Date: %d/%d/%d\n",hashArray[i].day -> dd,hashArray[i].day -> mm,hashArray[i].day -> yyyy);
        printf("Money: %.2f\n",hashArray[i].money);
        
    }
}
