#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"



struct NodoLista{
    TElemento info;
    struct NodoLista* sig;
};

typedef struct NodoLista TnodoLista;

typedef TnodoLista* TLinkedList;


TLinkedList crearVacia (TLinkedList* arbol);
void mostrar (TLinkedList arbol);
void insertar (TElemento elemento, TLinkedList* arbol);
void insertarFinal (TElemento elemento, TLinkedList* arbol);
int eliminar (TElemento elemento, TLinkedList* arbol);
void primero (TLinkedList arbol, TElemento* elemento);
void resto (TLinkedList* arbol);
void ultimo (TLinkedList arbol, TElemento* elemento);
void concatenar(TLinkedList* arbol1, TLinkedList arbol2);
int contiene (TElemento elemento, TLinkedList arbol);
int esVacia (TLinkedList arbol);
int longitud (TLinkedList arbol);

void copiar(TLinkedList original, TLinkedList* copia);
void destruir(TLinkedList* arbol);