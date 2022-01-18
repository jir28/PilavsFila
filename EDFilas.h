//
// Created by Jair on 18/01/22.
//
// Created by Jair on 10/01/22.
//
/*
Operaciones primitivas  de las filas en este archivo .h:
CrearFila()
FilaVacia()
AgregarAFila()
EliminarDeFila()
EliminarFila()
*/
#ifndef USOPILAS_EDPILA_H
#define USOPILAS_EDPILA_H
#include <stdlib.h>
#include <memory.h>

typedef struct TNodoFila{//Crear nodo para la fila
    void* Elem;//Comodin para que la fila permita guardar diferentes tipos de datos primitivos
    struct TNodoFila *Siguiente;
} TNodoFila;

typedef struct //definir la etiqueta del tope y guardar el tamaño del tipo de dato
{
    TNodoFila *Primero,*Ultimo; //Fila no necesita tope, pero si algo que señale el ultimo para agregar o primero para el caso de borrar
    int TamanioDato;
} TFila;


void CrearFila(TFila *pF, int TamanioDato)//*pF indireccion a la fila, tamaño de dato
{
    pF->Primero = pF->Ultimo = NULL; //Ambos nulos al crear la fila
    pF->TamanioDato = TamanioDato;
}

int FilaVacia(TFila F)
{
    return (F.Primero==NULL);
}

int AgregarAFila(TFila *pF, void* pE)
{
    TNodoFila *pNodo = (TNodoFila*) malloc(sizeof(TNodoFila));
    if (!pNodo)
        return 0;
    else
    {
        if(pF->Ultimo) {
            pF->Ultimo->Siguiente = pNodo;
        }
        if(!pF->Primero){
            pF->Primero=pNodo;
        }
        pNodo->Siguiente=NULL;
        pF->Ultimo=pNodo;
        pNodo->Elem = malloc (pF->TamanioDato);
        memcpy(pNodo->Elem, pE, pF->TamanioDato);
        return 1;
    }
}

int QuitardeFila(TFila *pC, void* pE)
{
    TNodoFila *pAux = pC->Primero;
    pC->Primero = pC->Primero->Siguiente;
    if(!pC->Primero){
        pC->Ultimo=NULL;
    }
    memcpy(pE, pAux->Elem, pC->TamanioDato);
    free(pAux->Elem);
    free(pAux);
    return 1;
}

#endif //USOPILAS_EDPILA_H
