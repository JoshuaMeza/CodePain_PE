//Programa que almacena "listas" con información del usuario y que determina el promedio de ganancias y si es o no una temporada
//baja o alta de ventas de la empresa.
//Realizado por Jonathan Gómez Benítez
//Versión 2.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//Se declaran las estructuras semana, dinero y node, las cuales almacenan diferentes tipos de dato e información.
//Se reserva una palabra para hacer llamada a dichas estructuras.
typedef struct semana{
    int semana;
    int mes;
}Semana;
typedef struct dinero{
    float cantidad;
    float promedio;
    float datos;
    Semana fecha;
}Dinero;
typedef struct node{
    Dinero datos;
    struct node *siguientenodo;
}NODO;
typedef NODO *Nodo; /* Node Pointer */

//Se declaran las funciones a utilizar, mismas que llevan el nombre de su tarea.
int desplegarMenu();
void borrarNodo(Nodo*,int *);
void continuarOperaciones(int *);
void asignarFecha(int*,int*,int*);
float asignarCantidad();
float obtenerPromedio(float, int);
void asignarOrden(Nodo*,int,float,int,int);
void imprimirListas(Nodo,float);
void imprimirBusqueda(Nodo);
void busquedaBinaria(Nodo);
int contarNodos(Nodo);
int compareTo(Nodo,int,int);

int main(){
    //Se declaran las variables de diferentes tipos a utilizar en el programa.
    Nodo PTRprincipal=NULL;
    int flag=1,i=0,semana,mes,option=0,sec1=0,sec2=0,lists=0,contador=0,total;
    float cantidad,promedio,sumador=0;

    //Se valida que la información proporcionada coincida con los parámetros esperados.

    while(option!=2){
        option=desplegarMenu();
        if(option==0){
            sec2=1;
            while(flag==1){
                lists+=1;
                fflush(stdin);
                asignarFecha(&semana,&mes,&total);
                while((semana<1 || semana>5) || (mes<1 || mes>12)){
                printf("\nAlguno de los datos ingresados no es correcto, ingreselos de nuevo.\n\n");
                asignarFecha(&semana,&mes,&total);
                }
                cantidad=asignarCantidad();
                sumador=sumador+cantidad;
                contador=contador+1;
                asignarOrden(&PTRprincipal,semana,cantidad,mes,total);
                continuarOperaciones(&flag);
            } 
        }else if(option==1){
            if(sec1==0){
                printf("No puedes borrar una lista si no tienes ninguna.\n");
                option=0;
            }else if(lists==0){
                printf("No puedes borrar una lista si no tienes ninguna.\n");
                option=0;
            }else if(lists==1){
                printf("No puedes borrar una lista si solo tienes una.\n");
                option=0;
            }else{
                borrarNodo(&PTRprincipal,&lists);
                lists-=1; 
            }
        }else if(option==2){
            if(sec2==0){
                printf("No puedes borrar una lista si no tienes ninguna.\n");
                option=0;
            }
        }else if(option==3){
            if(sec2==0){
                printf("No puedes borrar una lista si no tienes ninguna.\n");
                option=0;
            }else{
                busquedaBinaria(PTRprincipal);
            }
        }
    }
    promedio=obtenerPromedio(sumador,contador);
    //Se imprimen las listas que el usuario almacenó durante la ejecución.
    imprimirListas(PTRprincipal,promedio);

    return 0;
}

//Imprime el menu de las diferentes opciones del sistema, agregar, borrar o imprimir.
int desplegarMenu(){
    int seleccion;

    printf("-----------\n");
    printf("Menu\n");
    printf("-----------\n");
    printf("(1) Agregar una lista\n");
    printf("(2) Borrar una lista\n");
    printf("(3) Imprimir las listas\n");
    printf("(4) Buscar una lista\n");
    printf("-----------\n");
    printf("Ingrese su eleccion: ");
    scanf("%d",&seleccion);
    printf("-----------\n");
    seleccion-=1;

    if(seleccion<0 || seleccion>3){
        while(seleccion<0 || seleccion>3){
            printf("Error, ingrese un numero valido: ");
            scanf("%d",&seleccion);
        }
    }

    return seleccion;
}

//Se libera el espacio de memoria utilizado para almacenar el nodo que el usuario requiere.
void borrarNodo(Nodo *nptr,int *list){
    
    int _semana,_mes;
    Nodo temp, nodoActual=*nptr;

    printf("Para eliminar una lista ingrese la fecha.\n");
    printf("Ingrese el mes (1 a 12) : ");
    scanf("%d",&_mes);
    printf("Ingrese el numero de la semana del mes (1 a 5) : ");
    scanf("%d",&_semana);
    
    
    if(nodoActual -> datos.fecha.mes==_mes && nodoActual -> datos.fecha.semana==_semana){
        temp=nodoActual;
        *nptr=nodoActual->siguientenodo;
        temp -> siguientenodo=NULL;
        free(temp);
    }else{
        while(nodoActual -> datos.fecha.mes!=_mes && nodoActual -> datos.fecha.semana!=_semana){
            if(nodoActual -> siguientenodo==NULL){
                printf("-----------\n");
                printf("Los datos no existen\n");
                *list+=1;
                break;
            }
            temp=nodoActual;
            nodoActual=nodoActual -> siguientenodo;
        }
        if(nodoActual -> datos.fecha.mes==_mes && nodoActual -> datos.fecha.semana==_semana){
            if(nodoActual -> siguientenodo==NULL){
                nodoActual=temp;
                temp=nodoActual -> siguientenodo;
                nodoActual -> siguientenodo=NULL;
                free(temp);
            }else{
                nodoActual=temp;
                temp=nodoActual -> siguientenodo;
                nodoActual -> siguientenodo=temp -> siguientenodo;
                free(temp);
            }
        }
    }
}

//Despliega una pregunta que enlaza a la sección Main, básicamente es para saber si el usuario ha terminado o aún quiere hacer operaciones.
void continuarOperaciones(int *flag){
    char a;
    printf("-----------\n");
    printf("Quieres registrar otra semana? (S/N)\nR: ");
    scanf(" %c",&a);
    a=toupper(a);
    printf("-----------\n");
    
    if(a!='S' && a!='N'){
        while(a!='S' && a!='N'){
            printf("Por favor ingrese SI (S) o NO (N): ");
            scanf(" %c",&a);
            printf("\n-----------\n");
            a=toupper(a);
        }
    }

    if(a=='S'){
        *flag=1;
    }else{
        *flag=0;
    }
}

//Lee las variables mes y semana modificando el valor directamente con un apuntador.
void asignarFecha(int*semana,int*mes,int *total){
 printf("Ingrese el numero de semana (1 a 5) : ");
 scanf("%d",semana);
 
 printf("Ingrese el numero del mes (1 a 12) : ");
 scanf("%d",mes);

 *total=(*mes)*100+(*semana);
}

//Crea una variable cantidad, misma que es modificada con el valor que el usuario ingresa, retorno este mismo.
float asignarCantidad(){
   float _cantidad;

   printf("Ingrese la cantidad obtenida durante la semana: ");
   scanf("%f",&_cantidad);

   return _cantidad;
}
float obtenerPromedio(float sumador, int contador){
    float _promedio;
 _promedio=sumador/contador;
 return _promedio;
}

//Básicamente se asigna el orden en que las diferentes variables estarán almacenadas en las listas.
void asignarOrden(Nodo *nptr,int _semana,float _cantidad,int _mes,int _total){
    Nodo nuevoNodo, nodoActual=*nptr, nodoAnterior=NULL;

    nuevoNodo=(NODO*)malloc(sizeof(NODO)); 
    
    if(nuevoNodo!=NULL){
        nuevoNodo -> datos.fecha.semana=_semana;
        nuevoNodo -> datos.fecha.mes=_mes;
        nuevoNodo -> datos.cantidad=_cantidad;
        nuevoNodo ->datos.datos=_total;
        nuevoNodo -> siguientenodo=NULL;

        while(nodoActual!=NULL && _total>nodoActual -> datos.datos){
            nodoAnterior=nodoActual;
            nodoActual=nodoActual->siguientenodo;
        }

        if(nodoAnterior==NULL){
            nuevoNodo -> siguientenodo=*nptr;
            *nptr=nuevoNodo;
        }else{
            nodoAnterior ->siguientenodo=nuevoNodo;
            nuevoNodo -> siguientenodo=nodoActual;
        }
    }else{
        printf("No hay más espacio\n");
    }
}

//Imprime las listas almacenadas junto con un texto que define si es una temporada alta o baja de ventas en base al promedio de las mismas.
void imprimirListas(Nodo nodoActual,float _promedio){
    printf("El promedio de actual de ventas es de: %f\n",_promedio);
    if(nodoActual==NULL){
        printf("-----------\n");
        printf("Las listas están vacías");
        printf("-----------\n");
    }else{
        printf("-----------\n");
        printf("Listas:\n");

        while(nodoActual!=NULL){
            printf("-----------\n");
            printf("Semana: %d Mes: %d\n",nodoActual->datos.fecha.mes,nodoActual->datos.fecha.semana);
            printf("Cantidad: $%.2f\n",nodoActual->datos.cantidad);
            if (nodoActual->datos.cantidad>_promedio)
            {
                printf("Temporada Alta\n");
            } else{
                printf("Temporada Baja\n");
            }


            nodoActual=nodoActual->siguientenodo;
        }
        printf("-----------\n");
    }
}

//Básicamente cuenta el total de listas que han sido almacenadas por el usuario
int contarNodos(Nodo nptr){
   
    int contadorNodos=0;

    while(nptr -> siguientenodo!=NULL){
        contadorNodos+=1;
        nptr=nptr -> siguientenodo;
    }

    return contadorNodos;
}

//Pide al usuario la información que desea buscar, realiza el proceso de búsqueda y llama a la función imprimirBusqueda
//en caso de que se haya encontrado lo que se deseaba.
void busquedaBinaria(Nodo nptr){
    int contadorNodos,izquierda=0,derecha,medio,dato,resultado,flag=0,i;

    contadorNodos=contarNodos(nptr);
    derecha=contadorNodos;
    int _semana,_mes,_total;

    printf("Para buscar la lista ingrese la fecha\n");
    printf("Ingrese la semana: ");
    scanf("%d",&_semana);
    printf("Ingrese el mes: ");
    scanf("%d",&_mes);
    _total=_mes*100+_semana;
    dato=_total;

    while(izquierda<=derecha){
    
        medio=(izquierda+derecha)/2;

        resultado=compareTo(nptr,dato,medio);

        if(resultado==0){
            for(i=0;i<medio;i++){
                nptr=nptr -> siguientenodo;
            }
            flag=1;
            break;
        }else if(resultado==-1){
            derecha=medio-1;
        }else if(resultado==1){
            izquierda=derecha+1;
        }
    }
    
    if(flag==0){
        printf("-----------\n");
        printf("No existe esa fecha.\n");
    }else{
        imprimirBusqueda(nptr);  
    }
}

//Compara los datos ingresados por el usuario para buscarlos en las listas, retorna un valor diferente en función
//de cómo fue la búsqueda
int compareTo(Nodo nptr,int dato,int medio){
   int i,resultado;

    for(i=0;i<medio;i++){
       nptr=nptr->siguientenodo;
    }

    if(dato==nptr -> datos.datos){
        resultado=0;
    }else if(dato<nptr -> datos.datos){
        resultado=-1;
    }else{
        resultado=1;
    }

    return resultado;
}

//Imprime la lista que contiene los datos de la búsqueda binaria (en caso de existir)
void imprimirBusqueda(Nodo nodoActual){
    printf("-----------\n");
    printf("Semana: %d\n",nodoActual->datos.fecha.semana);
    printf("Mes: %d\n",nodoActual->datos.fecha.mes);
    printf("Cantidad vendida: $%f\n",nodoActual->datos.cantidad);
}
