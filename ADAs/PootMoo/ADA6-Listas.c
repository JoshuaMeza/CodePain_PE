/*  Author Irving Eduardo Poot Moo
    Version 1.0.0
    Programa que genera, elimina e imprime las listas con el numero de temporada y cantidad registrada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
/*
Se definen las estructuras y procesos necesarias para trabajar
*/
typedef struct temporada{
    int numero;
    float cantidad;
}Temporada;

typedef struct node{
    Temporada dato;
    struct node *nextnode;
}NODO;

typedef NODO *Nodo; //Apuntador al nodo

int menu();
void borrar(Nodo*, int *);
void decision(int *);
float asignaCantidad();
int asignaTemporada();
void ordenar(Nodo*, int, float);
void imprimirLista(Nodo);

int main(){
    // Entradas
    Nodo PTRprincipal=NULL;
    int ins=1, i=0, res=0, sec1=0, sec2=0, listas=0, temporada;
    float cantidad;

    while(res!=2){
        res=menu();
        system("clear");
        //Proceso
        if(res==0){
            sec1=1;
            sec2=1;
            while(ins==1){
                listas+=1;
                fflush(stdin);
                temporada=asignaTemporada();
                cantidad=asignaCantidad();
                ordenar(&PTRprincipal,temporada,cantidad);
                decision(&ins);
            }
        }else if(res==1){
            if(sec1==0){
                printf("No se puede borrar una lista si no se tiene alguna.\n");
                res=0;
            }else if(listas==0){
                printf("No se puede borrar una lista si no se tiene alguna.\n");
                res=0;
            }else if(listas==1){
                printf("No se puede borrar una lista si no se tiene alguna.\n");
                res=0;
            }else{
                borrar(&PTRprincipal,&listas);
                listas-=1; 
            }
        }else{
            if(sec2==0){
                printf("No se pueden imprimir las listas si no hay alguna.\n");
                res=0;
            }else if(listas==0){
                printf("No se pueden imprimir las listas si no hay alguna.\n");
                res=0;
            }
        }
    }
    //Salidas
    imprimirLista(PTRprincipal);

    return 0;
}

int menu(){
    //Genera un menu para que el usuario decida que hacer
   int ins=0;

   printf("******************************************\n");
   printf("    ¿Qué desea hacer?    \n");
   printf("1- Agregar una lista             \n");
   printf("2- Borrar una lista             \n");
   printf("3- Imprimir listas             \n");
   printf("******************************************\n");
   scanf("%d",&ins);
   ins-=1;

   if(ins<0 , ins>2){
       while(ins<0 , ins>2){
           printf("Numero invalido, Ingrese otro\n");
           scanf("%d",&ins);
       }
   }
   return ins;
}

int asignaTemporada(){
    // Recibe el numero de temporada que se quiere ingresar 
    int temporada;

    printf("¿Qué temporada desea registrar?\n");
    scanf("%d",&temporada);

    return temporada;
}

float asignaCantidad(){
    //Recibe la cantidad que se desea ingresar en la temporada
    float cantidad;

    printf("¿Qué cantidad desea registrar?\n");
    scanf("%f",&cantidad);

    return cantidad;
}

void ordenar(Nodo *nptr, int temporada, float cantidad){
    // Ordena la temporada y cantidad en el lugar donde corresponden en las estructuras
    Nodo nuevo, actual=*nptr,anterior=NULL;

    nuevo=(NODO*)malloc(sizeof(NODO));

    if(nuevo!=NULL){
        nuevo -> dato.numero=temporada;
        nuevo -> dato.cantidad=cantidad;
        nuevo -> nextnode=NULL;

        while(actual!=NULL){
            anterior=actual;
            actual=actual -> nextnode;
        }

        if(anterior==NULL){
            nuevo -> nextnode=*nptr;
            *nptr=nuevo;
        }else{
            anterior -> nextnode=nuevo;
            nuevo -> nextnode=actual;
        }
    }else{
        printf("Espacio insuficiente \n");
    }
}

void decision(int *ins){
    // Le pregunta al usuario si quiere agregar alguna temporada más
    char res;
    printf("******************************************\n");
    printf("    ¿Desea agregar otra temporada?    \n");
    printf("           Si (S) o No (N)             \n");
    printf("******************************************\n");
    scanf("%c",&res);
    res=toupper(res);

    if(res!='S' && res!='N'){
        while (res!='S' && res!='N'){
            printf("Respuesta invalida, por favor responda como se indica");
            scanf("%c",&res);
            res=toupper(res);
        }
        
    }

    if(res=='S'){
        *ins=1;
    }else{
        *ins=0;
    }
}

void borrar(Nodo *nptr, int *lista){
    // Borra la lista que se le indica
    int numero, cantidad;
    Nodo aux, actual=*nptr;
    
    printf("Para eliminar una lista ingrese el numero de temporada.\n");
    scanf("%d",&numero);
    printf("Ingrese la cantidad asignada a esa temporada");
    scanf("%d",&cantidad);

    if(actual -> dato.numero==numero && actual -> dato.cantidad==cantidad){
        aux = actual;
        *nptr = actual -> nextnode;
        aux -> nextnode=NULL;
        free(aux);
    }else{
        while(actual -> dato.numero!=numero && actual -> dato.cantidad!=cantidad){
            if(actual -> nextnode==NULL){
                printf("No existen datos \n");
                *lista+=1;
                break;
            }
            aux = actual;
            actual=actual -> nextnode;
        }
        if(actual -> dato.numero==numero && actual -> dato.cantidad==cantidad){
            if(actual -> nextnode==NULL){
                actual=aux;
                aux=actual -> nextnode;
                actual -> nextnode=NULL;
                free(aux);
            }else{
                actual=aux;
                aux=actual -> nextnode;
                actual -> nextnode=aux -> nextnode;
                free(aux);
            }
        }
    }
}

void imprimirLista(Nodo actual){
    //Imprime todas las listas generadas
    if(actual==NULL){
        printf("*************************\n");
        printf("La lista está vacía\n");
        printf("*************************\n");
    }else{
        printf("*************************\n");
        printf("Listas:\n");

        while (actual!=NULL){
            printf("*************************\n");
            printf("Temporada No. %d\n", actual -> dato.numero);
            printf("Cantidad ingresada en esta temporada: $%.2f\n", actual -> dato.cantidad);
        
            actual = actual -> nextnode;
        }
        printf("*************************\n");
    }
}