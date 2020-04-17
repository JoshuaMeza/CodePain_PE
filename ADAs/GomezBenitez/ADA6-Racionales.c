//Programa que calcula las operaciones básicas entre dos racionales y que los simplifica
//Versión 2.0
//Realizado por Jonathan Gómez
#include <stdio.h>
//Se declara la estructura "racional", la cual hace uso de dos variables que almacenan lo que su nombre dice.
struct racional{
int numerador;
int denominador;
};
//Se declaran las funciones que llevan a cabo la lectura, operaciones básicas, simplificación e impresión.
//Se usa un ciclo while para evitar que se den racionales con denominador == 0, puesto que estos no existen.
void leerNumerador(struct racional *,struct racional *);
void leerDenominador(struct racional *,struct racional *);
void sumarRacional(struct racional,struct racional, struct racional*);
void restarRacional(struct racional,struct racional,struct racional*);
void multiplicarRacional(struct racional,struct racional,struct racional*);
void dividirRacional(struct racional,struct racional,struct racional*);
void simplificarRacional(struct racional*);
void imprimirResultados(struct racional,struct racional,struct racional,struct racional);

int main(){
 //Se declara la estructura "racional", la matriz resultados (la cual sirve para almacenar los numeradores y denominadores
 //de cada operación para hacer uso del mcd y simplificarlos, además de imprimirlos con la apariencia "a/b").
 struct racional r1, r2,resultados1,resultados2,resultados3,resultados4;
 //Se incluyen todas las funciones a excepción de la simplificación, misma que es llamada durante cada función de
 //operación para efectuarse.
 leerNumerador(&r1,&r2);
 leerDenominador(&r1,&r2);
 sumarRacional(r1,r2,&resultados1);
 restarRacional(r1,r2,&resultados2);
 multiplicarRacional(r1,r2,&resultados3);
 dividirRacional(r1,r2,&resultados4);
 imprimirResultados(resultados1,resultados2,resultados3,resultados4);
 return 0;
}
//Lee los numeradores de cada racional y los almacena en la estructura mencionada anteriormente.
void leerNumerador(struct racional *r1,struct racional *r2){
 printf("Ingrese el NUMERADOR del RACIONAL 1: ");
 scanf("%d",&r1->numerador);
 printf("Ingrese el NUMERADOR del RACIONAL 2: ");
 scanf("%d",&r2->numerador);
}
//Lee los denominadores de cada racional y los almacena en la estructura mencionada anteriormente.
void leerDenominador(struct racional *r1,struct racional *r2){
 printf("Ingrese el DENOMINADOR del RACIONAL 1: ");
 scanf("%d",&r1->denominador);
 while(r1->denominador==0){
     printf("No existen DENOMINADORES iguales a 0, ingrese de nuevo\n");
     printf("Ingrese el DENOMINADOR del RACIONAL 1: ");
     scanf("%d",&r1->denominador); 
 }
 printf("Ingrese el DENOMINADOR del RACIONAL 2: ");
 scanf("%d",&r2->denominador);
 while(r2->denominador==0){
     printf("No existen DENOMINADORES iguales a 0, ingrese de nuevo\n");
     printf("Ingrese el DENOMINADOR del RACIONAL 2: ");
     scanf("%d",&r2->denominador);
 }
}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la suma del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void sumarRacional(struct racional r1,struct racional r2, struct racional *resultados1){

 resultados1->numerador=r1.numerador*r2.denominador+r2.numerador*r1.denominador;
 resultados1->denominador=r1.denominador*r2.denominador;
 simplificarRacional(resultados1);

}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la resta del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void restarRacional(struct racional r1, struct racional r2, struct racional *resultados2){
 resultados2->numerador=r1.numerador*r2.denominador-r2.numerador*r1.denominador;
 resultados2->denominador=r1.denominador*r2.denominador;
 simplificarRacional(resultados2);
}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la multiplicación del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void multiplicarRacional(struct racional r1, struct racional r2, struct racional *resultados3){
 resultados3->numerador=r1.numerador*r2.numerador;
 resultados3->denominador=r1.denominador*r2.denominador;
 simplificarRacional(resultados3);
}
//Haciendo llamada a los valores leídos en las funciones anteriores, realiza la división del racional 1 y 2, entonces
//almacena el numerador y denominador resultante en la matriz "resultados", posteriormente hace llamada a la simplificación.
void dividirRacional(struct racional r1, struct racional r2, struct racional *resultados4){
 resultados4->numerador=r1.numerador*r2.denominador;
 resultados4->denominador=r1.denominador*r2.numerador;
 simplificarRacional(resultados4);
}
//Haciendo uso del algoritmo de Euclides, se obtiene el MCD del numerador y denominador correspondientes con el apoyo
//de dos variables aux1 y aux2, mismas que almacenan temporalmente el valor de "resultados" para llevar a cabo el
//proceso antes mencionado, requiere de la posición de la función a simplificar.
void simplificarRacional(struct racional *resultados){
 if(resultados->numerador!=0 & resultados->denominador!=0){
     int aux1=resultados->numerador, aux2=resultados->denominador;

 while(aux1!=aux2 & aux1>0 & aux2>0){
     if (aux1>aux2){
         aux1=aux1-aux2;
     } else {
         aux2=aux2-aux1;
     }
}
 if(resultados->numerador != resultados->denominador){
     resultados->numerador=resultados->numerador/aux1;
     resultados->denominador=resultados->denominador/aux1;
 }
 }

}
//Usando una serie de condiciones, las cuales cubren los posibles casos de salida y simplificación, imprime el resultado
//de cada operación básica en su forma más simplificada.
void imprimirResultados(struct racional resultados1 ,struct racional resultados2 ,struct racional resultados3,struct racional resultados4){
    if(resultados1.numerador==resultados1.denominador){
        printf("El resultado de la SUMA es: 1\n");
    } else{
        if((resultados1.numerador>resultados1.denominador) & resultados1.denominador==1){
            printf("El resultado de la SUMA es: %d\n", resultados1.numerador);
        } else {
            if(resultados1.numerador==0){
                printf("El resultado de la SUMA es: 0\n");
            } else{
                printf("El resultado de la SUMA es: %d/%d\n",resultados1.numerador,resultados1.denominador);
            }
        }
    }
    if(resultados2.numerador==resultados2.denominador){
        printf("El resultado de la RESTA es: 1\n");
    } else{
        if((resultados2.numerador>resultados2.denominador) & resultados2.denominador==1){
            printf("El resultado de la RESTA es: %d\n", resultados2.numerador);
        } else {
            if(resultados2.numerador==0){
                printf("El resultado de la RESTA es: 0\n");
            } else{
                printf("El resultado de la RESTA es: %d/%d\n",resultados2.numerador,resultados2.denominador);
            }
        }
    }
    if(resultados3.numerador==resultados3.denominador){
        printf("El resultado de la MULTIPLICACION es: 1\n");
    } else{
        if((resultados3.numerador>resultados3.denominador) & resultados3.denominador==1){
            printf("El resultado de la MULTIPLICACION es: %d\n", resultados3.numerador);
        } else {
            if(resultados3.numerador==0){
                printf("El resultado de la MULTIPLICACION es: 0\n");
            } else{
                printf("El resultado de la MULTIPLICACION es: %d/%d\n",resultados3.numerador,resultados3.denominador);
            }
        }
    }
    if(resultados4.numerador==resultados4.denominador){
        printf("El resultado de la DIVISION es: 1\n");
    } else{
        if((resultados4.numerador>resultados4.denominador) & resultados4.denominador==1){
            printf("El resultado de la DIVISION es: %d\n", resultados4.numerador);
        } else {
            if(resultados4.numerador==0){
                printf("El resultado de la DIVISION es: 0\n");
            } else{
                printf("El resultado de la DIVISION es: %d/%d\n",resultados4.numerador,resultados4.denominador);
            }
        }
    }
}
