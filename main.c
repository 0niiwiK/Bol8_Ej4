#include <stdio.h>
#include "math.h"
int pideNumero();
void buscaPrimos(int num,int num2);
void imprimePrimo(int num,int cont);
int noEsPrimo(int num);

int main() {
    int num;
    buscaPrimos(pideNumero(),pideNumero());
}

int pideNumero(){
    int num;
    printf("Introduce un valor entero positivo: ");
    scanf("%d",&num);
    fflush(stdin);
    while (num<=0){
        printf("El numero debe ser positivo y no nulo");
        printf("\nIntroduce un valor entero positivo: ");
        scanf("%d",&num);
        fflush(stdin);
    }
    return num;
}
void buscaPrimos(int num,int num2){
    // Un numero solo puede ser primo si solo es divisible por la unidad y por si mismo,
    // no puede ser divisible por ningún otro numero primo contenido desde
    // el numero 2 hasta la raiz cuadrada del numero a evaluar.
    int cont_primos=0;
    for (int contador=num; contador<=(int)((num2)^(1/2)) ; contador++) {
        if (noEsPrimo(contador) != 1){
            cont_primos++;
            imprimePrimo(contador,cont_primos);
        }
    }
}
void imprimePrimo(int num,int cont){
    printf("Primo %d: %d\n",cont,num);
}
int noEsPrimo(int num){
    int esPrimo=0;
    int contador=2;
        while (contador<=((int)(sqrt(num))) && (esPrimo!=1)){
            if (num%contador==0)
                esPrimo=1;
            else
                contador++;
        }
    return esPrimo;
}
