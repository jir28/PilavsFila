#include <stdio.h>
#include <stdlib.h>
#include "EDFilas.h"
#include "EDPila.h"


int pilaFila(TPila *pP,TFila *pF){

    int dato=3,x,y,r;
    Apilar(pP,&dato);
    dato = 12;
    Apilar(pP,&dato);
    dato = 5;
    AgregarAFila(pF,&dato);
    dato = 8;
    AgregarAFila(pF,&dato);
    Desapilar(pP,&dato);
    x = dato;
    dato=2;
    Apilar(pP,&dato);
    AgregarAFila(pF,&x);
    QuitardeFila(pF,&dato);
    y=dato;
    Apilar(pP,&x);
    Apilar(pP,&y);
    Desapilar(pP,&dato);
    r=dato;
    return r;
}

int main() {
    TPila S;
    TFila Q;
    int dato,resul;

    CrearPila(&S,sizeof(dato));
    CrearFila(&Q,sizeof(dato));

    resul = pilaFila(&S,&Q);
    printf("El numero tope de la pila es: %d",resul);
    return 0;
}
