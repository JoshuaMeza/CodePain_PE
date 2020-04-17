/*  Author Irving Eduardo Poot Moo
    Version 1.0.0
    Programa que hace operaciones de fracciones utilizando estructuras
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct racional {
    int numerador;
    int denominador;
};

int getIns();
void leerNumerador(struct racional *, struct racional *);
void sumarRacional(struct racional, struct racional, int resultado[][1]);
void restarRacional(struct racional, struct racional, int resultado[][1]);
void multiplicarRacional(struct racional, struct racional, int resultado[][1]);
void dividirRacional(struct racional, struct racional, int resultado[][1]);
void simplificarRacional(int resultado[][1]);
int mcd(int resultado[][1]);
void simplificarUnico(int resultado[][1]);
void imprimirResultado(int resultado[][1]);
int makeDecition();
void sayGoodbye();

int main(){
    int decision = 1, checkIns;
    while(decision==1){
        // Entradas
        struct racional r1, r2;
        int resultado[1][1];
        checkIns = getIns();
        system("clear");
        // Proceso
        if(checkIns==1){
            sumarRacional(r1, r2, resultado);

        }else if(checkIns==2){
            restarRacional(r1, r2, resultado);

        }else if(checkIns==3){
            multiplicarRacional(r1, r2, resultado);

        }else if(checkIns==4){
            dividirRacional(r1, r2, resultado);

        }else if(checkIns == 5){
            simplificarUnico(resultado);
        }

        // Salidas
        imprimirResultado(resultado);

        //Return Cycle
        decision = makeDecition();
        system("clear");
    }
    sayGoodbye();

}

int getIns(){
    /*  Pregunta que se quiere hacer
    Args:
        ins (int): Pregunta por la orden
    Returns:
        La orden seleccionada
    */
   int ins=0;
   printf("******************************************\n");
   printf("    -¿Que desea hacer?-    \n");
   printf("1- Sumar racionales             \n");
   printf("2- Restar racionales             \n");
   printf("3- Multiplicar racionales             \n");
   printf("4- Dividir racionales             \n");
   printf("5- Simplificar un racional             \n");
   printf("******************************************\n");
   printf("¿Entonces?\n");
   scanf("%d",&ins);

   if(ins<1 , ins>5){
       while(ins<1 , ins>5){
           printf("No existe esa opcion, Selecione otra\n");
           scanf("%d",&ins);
       }
   }
   return ins; 
}

void leerRacional(struct racional *r1, struct racional*r2){
    /* Lee los racionales con los que se quiere trabajar
    Args:
        r1 (struct): Primer racional
        r2 (struct): Segundo racional
    Returns:
        Los numeradores
    */

   printf("Inserte el primer numerador: ");
   scanf("%d", &r1 -> numerador);
   printf("Inserte el primer denominador: ");
   scanf("%d", &r1 -> denominador);

   printf("Inserte el segundo numerador: ");
   scanf("%d", &r2 -> numerador);
   printf("Inserte el segundo denominador: ");
   scanf("%d", &r2 -> denominador);

}

void sumarRacional(struct racional r1, struct racional r2, int resultado[][1]){
    /* Hace la suma de fracciones
    Args:
        resultado (array): contiene el resultado de las operaciones hechas
        r1 (struct): Primer racional dado
        r2 (struct): Segundo racional dado
    Returns:
        La suma de las fracciones
    */

    resultado[0][0]=r1.numerador*r2.denominador+r1.denominador*r2.numerador;
    resultado[0][1]=r1.denominador*r2.denominador;

    simplificarRacional(resultado);
}

void restarRacional(struct racional r1, struct racional r2, int resultado[][1]){
    /* Hace la resta de fracciones
    Args:
        resultado (array): contiene el resultado de las operaciones hechas
        r1 (struct): Primer racional dado
        r2 (struct): Segundo racional dado
    Returns:
        La resta de las fracciones
    */

    resultado[0][0]=r1.numerador*r2.denominador-r1.denominador*r2.numerador;
    resultado[0][1]=r1.denominador*r2.denominador;

    simplificarRacional(resultado);
}

void multiplicarRacional(struct racional r1, struct racional r2, int resultado[][1]){
    /* Hace la multiplicacion de fracciones
    Args:
        resultado (array): contiene el resultado de las operaciones hechas
        r1 (struct): Primer racional dado
        r2 (struct): Segundo racional dado
    Returns:
        La multiplicacion de las fracciones
    */

    resultado[0][0]=r1.numerador*r2.numerador;
    resultado[0][1]=r1.denominador*r2.denominador;

    simplificarRacional(resultado);
}

void dividirRacional(struct racional r1, struct racional r2, int resultado[][1]){
    /* Hace la division de fracciones
    Args:
        resultado (array): contiene el resultado de las operaciones hechas
        r1 (struct): Primer racional dado
        r2 (struct): Segundo racional dado
    Returns:
        La division de las fracciones
    */
    resultado[0][0]=r1.numerador*r2.denominador;
    resultado[0][1]=r1.denominador*r2.numerador;

    simplificarRacional(resultado);
}

void simplificarRacional(int resultado[0][1]){
    /* Hace la simplificacion de la fraccion
    Args:
        resultado (array): contiene el resultado de las operaciones hechas
        maxcomdiv (int): contiene el maximo comun divisor de la fraccion
    Returns:
        La fraccion simplificada
    */
    int maxcomdiv;
    maxcomdiv=mcd(resultado[1][1]);
    resultado[0][0]=resultado[0][0]/maxcomdiv;
    resultado[0][1]=resultado[0][1]/maxcomdiv;
}

int mcd(int resultado[][1]){
    /* Calcula el maximo comun divisor con los elementos de la fraccion
    Args:
        resultado (array): contiene el resultado de las operaciones hechas
        res (int): contiene el mcd calculado
        i (int): filas
        j (int): columnas
    Returns:
        El maximo comun divisor
    */
    int res=1;
    for(int i=1;i<=resultado[0][0];i++){
        if ((resultado[0][0]%i==0) && (resultado[0][1]%i==0)){
            res=i;
        }
    }

    return res;
}

void simplificarUnico(int resultado[][1]){
    /* Hace solo la simplificacion de la fraccion dada
    Args:
        resultado (array): contiene la fraccion introducida
    Returns:
        El numero dado
    */
    printf("Inserte el numerador: ");
    scanf("%d", &resultado[0][0]);
    printf("Inserte el denominador: ");
    scanf("%d", &resultado[0][1]);

    simplificarRacional(resultado);
}

void imprimirResultado(int resultado[][1]){
    /* Imprime el resultado de todas las operaciones anteriores
    Args:
        resultado (array): contiene el resultado de las operaciones hechas
    Returns:
        Nothing
    */
    printf("El resultado es: %d/%d", resultado[0][0], resultado[0][1]);
}

int makeDecition(){
    int decision=0;
    printf("    ¿Necesitas otra operacion?    \n");
    printf("    1)Si  o  2)No    \n");
    scanf("%d",&decision);
    
    return decision;
}

void sayGoodbye(){
    printf("    Bye, Bye :)    ");
}