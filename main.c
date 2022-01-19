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

int pilaFila2(TPila *pP, TFila *pF, TFila *ptr) {
    int dato = 5,z,x,r;
    AgregarAFila(pF,&dato);
    dato = 6;
    AgregarAFila(pF,&dato);
    dato = 9;
    AgregarAFila(pF,&dato);
    dato = 0;
    AgregarAFila(pF,&dato);
    dato = 7;
    AgregarAFila(pF,&dato);
    dato = 5;
    AgregarAFila(pF,&dato);
    dato = 0;
    AgregarAFila(pF,&dato);
    dato = 2;
    AgregarAFila(pF,&dato);
    dato = 6;
    AgregarAFila(pF,&dato);

    while (FilaVacia(*pF)!=1){
        QuitardeFila(pF,&dato);
        x = dato;
        if (dato==0){
            z=0;
            while (PilaVacia(*pP)!=1){
                Desapilar(pP,&dato);
                z = z + 1;
                AgregarAFila(ptr,&z);
            }
        } else{
            Apilar(pP,&x);
        }
    }
    Desapilar(pP,&dato);
    r = dato;
    return r;
}

int main() {
    TPila S;
    TFila Q,Q1,Q2;
    int dato,resul,res2;

    CrearPila(&S,sizeof(dato));
    CrearFila(&Q,sizeof(dato));
    resul = pilaFila(&S,&Q);
    printf("El numero tope de la pila es: %d",resul);

    CrearFila(&Q1,sizeof (dato));
    CrearFila(&Q2,sizeof (dato));
    CrearPila(&S, sizeof(dato));
    res2 = pilaFila2(&S, &Q1, &Q2);
    printf("\nEl valor de la pila al final de la 2 es: %d",res2);

    return 0;
}
